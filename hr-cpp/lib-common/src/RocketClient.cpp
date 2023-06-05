/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 16:17:08
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
      https://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "pch.h"
#include <iostream>
#include <sstream>
#include <mutex>
#include <chrono>
#include <thread>
#include "RocketClient.h"
using namespace std;
using namespace std::chrono;

// 生成一个实例名称
#define RCMQ_INSTANCE_NAME_MK(_TAG_) \
auto now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count(); \
stringstream ss; \
ss << groupname << "@" << _TAG_ << "-" << now; \
string instanceName = ss.str() 

// 定义一个全局互斥锁
std::mutex rocket_mq_mtx;

RocketClient::RMessageLisenter::RMessageLisenter(RocketClient* client)
{
	this->client = client;
}

rocketmq::ConsumeStatus RocketClient::RMessageLisenter::consumeMessage(const std::vector<MQMessageExt>& msgs)
{
	std::unique_lock<std::mutex> lck(rocket_mq_mtx);
	for (const MQMessageExt& msg : msgs)
	{
#ifdef _DEBUG
		cout << "RMessageLisenter: " << msg.getBody() << endl;
#endif
		for (auto listener : client->m_listeners)
		{
			listener->receiveMessage(msg.getBody());
		}
	}
	return ConsumeStatus::CONSUME_SUCCESS;
}

void RocketClient::RAutoDeleteSendCallback::onSuccess(SendResult& sendResult)
{
	cout << "RAutoDeleteSendCallback: send success, status is " << sendResult.getSendStatus() << endl;
}

void RocketClient::RAutoDeleteSendCallback::onException(MQException& e)
{
	cout << "RAutoDeleteSendCallback: send exception, " << e << endl;
}

RocketClient::RSendCallback::RSendCallback(std::function<void(SendStatus)> cf)
{
	this->cf = cf;
}

void RocketClient::RSendCallback::onSuccess(SendResult& sendResult)
{
	// 呼叫回调
	cf(sendResult.getSendStatus());
}

void RocketClient::RSendCallback::onException(MQException& e)
{
	cout << "RSendCallback: send exception, " << e.what() << endl;
	// 呼叫回调
	cf(SendStatus::SEND_FLUSH_DISK_TIMEOUT);
}

void RocketClient::releaseProducer()
{
	if (m_producer)
	{
		m_producer->shutdown();
		delete m_producer;
		m_producer = nullptr;
		cout << "producer shutdown finish." << endl;
	}
}

void RocketClient::releaseConsumer()
{
	if (m_consumer)
	{
		m_consumer->shutdown();
		delete m_consumer;
		m_consumer = nullptr;
		cout << "consumer shutdown finish." << endl;
	}
}

RocketClient::RocketClient(const std::string& namesrv, const std::string& groupName /*= "cpp-rocketmq"*/)
{
	this->namesrv = namesrv;
	this->groupname = groupName;
	this->m_topic = "";
	this->m_producer = nullptr;
	this->m_consumer = nullptr;
	this->m_msgListener = new RMessageLisenter(this);
}

RocketClient::~RocketClient()
{
	delete this->m_msgListener;
	releaseConsumer();
	releaseProducer();
}

void RocketClient::productMsgAsync(const std::string& topic, const std::string& body, SendCallback* cb /*= nullptr*/)
{
	// 生成一个实例名称
	RCMQ_INSTANCE_NAME_MK("async-producer");
	// 创建生产者
	auto producer = new DefaultMQProducer(groupname);
	producer->setNamesrvAddr(namesrv);
	producer->setInstanceName(instanceName);
	// 回调定义
	SendCallback* delCallBack = nullptr;
	if (!cb) delCallBack = new RAutoDeleteSendCallback();
	// 启动生产者
	try {
		producer->start();
	}
	catch (MQException& e) {
		if (cb)
			cb->onException(e);
		else
		{
			delCallBack->onException(e);
			delete delCallBack;
		}
		delete producer;
		return;
	}
	// 创建发送消息线程
	std::thread th([=]() 
		{
			// 创建消息对象
			MQMessage msg(topic, body);
			// 发送消息
			try {
				if (cb)
					producer->send(msg, cb);
				else
					producer->send(msg, delCallBack);
			}
			catch (MQException& e) {
				if (cb)
					cb->onException(e);
				else
				{
					delCallBack->onException(e);
					delete delCallBack;
				}
			}
			producer->shutdown();
			delete producer;
		});
	th.detach();
}

rocketmq::SendStatus RocketClient::productMsgSync(const std::string& topic, const std::string& body)
{
	// 创建生产者
	if (!m_producer || this->m_topic != topic)
	{
		// 首先释放资源
		releaseProducer();
		// 设置当前消费者
		this->m_topic = topic;
		// 生成一个实例名称
		RCMQ_INSTANCE_NAME_MK("sync-producer");
		// 设置生产者属性
		m_producer = new DefaultMQProducer(groupname);
		m_producer->setNamesrvAddr(namesrv);
		m_producer->setInstanceName(instanceName);
		try
		{
			m_producer->start();
		}
		catch (MQException& e)
		{
			cout << "Sync start fail: " << e << endl;
			return rocketmq::SendStatus::SEND_FLUSH_DISK_TIMEOUT;
		}
	}
	// 创建消息对象
	MQMessage msg(topic, body);
	// 发送消息
	try {
		SendResult sendResult = m_producer->send(msg);
		return sendResult.getSendStatus();
	}
	catch (const MQException& e) {
		cout << "Sync send fail: " << e << endl;
		return rocketmq::SendStatus::SEND_FLUSH_DISK_TIMEOUT;
	}
}

bool RocketClient::subscribe(const std::string& topic)
{
	// 判断是否已经订阅过
	if (m_consumer)
	{
		std::cerr << "already subscribed, no need to subscribe again." << std::endl;
		std::cerr << "but you can unsubscribe and then subscribe." << std::endl;
		return true;
	}

	// 生成一个实例名称
	RCMQ_INSTANCE_NAME_MK("push-consumer");
	
	// 创建消费者
	m_consumer = new DefaultMQPushConsumer(groupname);
	m_consumer->setNamesrvAddr(namesrv);
	m_consumer->setInstanceName(instanceName);
	m_consumer->setConsumeFromWhere(CONSUME_FROM_LAST_OFFSET);
	m_consumer->setMessageModel(rocketmq::BROADCASTING);
	m_consumer->subscribe(topic, "*");
	m_consumer->setConsumeThreadCount(1);
	m_consumer->setTcpTransportTryLockTimeout(1000);
	m_consumer->setTcpTransportConnectTimeout(400);
	// 注册事件监听
	m_consumer->registerMessageListener(this->m_msgListener);
	m_consumer->setAsyncPull(true);
	m_consumer->setMessageTrace(true);
	try {
		m_consumer->start();
	}
	catch (MQException& e) {
		std::cout << "consumer start fail: " << e << endl;
		releaseConsumer();
		return false;
	}
	return true;
}

void RocketClient::unsubscribe()
{
	releaseConsumer();
}

void RocketClient::addListener(RConsumerListener* listener)
{
	std::unique_lock<std::mutex> lck(rocket_mq_mtx);
	m_listeners.push_back(listener);
}

void RocketClient::removeListener(RConsumerListener* listener)
{
	std::unique_lock<std::mutex> lck(rocket_mq_mtx);
	auto iter = std::find(m_listeners.begin(), m_listeners.end(), listener);
	if (iter != m_listeners.end())
	{
		m_listeners.erase(iter);
	}
}

void RocketClient::removeAllListener()
{
	std::unique_lock<std::mutex> lck(rocket_mq_mtx);
	m_listeners.clear();
}
