#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 16:12:41
 
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
#ifndef _ROCKETCLIENT_H_
#define _ROCKETCLIENT_H_
#define WIN32_LEAN_AND_MEAN

#ifdef LINUX
#include "unistd.h"
#include <functional>
#endif
#include "rocketmq/DefaultMQProducer.h"
#include "rocketmq/DefaultMQPushConsumer.h"
using namespace rocketmq;

/**
 * 定义一个Rocketmq客户端，来封装常用操作。
 * 参考连接：https://github.com/apache/rocketmq-client-cpp/tree/release-2.1.0/example
 */
class RocketClient
{
private:
	/**
	 * MQ消息监听器
	 */
	class RMessageLisenter : public MessageListenerConcurrently {
	private:
		RocketClient* client;
	public:
		explicit RMessageLisenter(RocketClient* client);
		ConsumeStatus consumeMessage(const std::vector<MQMessageExt>& msgs) override;
	};
	/**
	 * MQ自动删除回调
	 */
	class RAutoDeleteSendCallback : public AutoDeleteSendCallBack {
	public:
		void onSuccess(SendResult& sendResult) override;
		void onException(MQException& e) override;
	};
public:
	/**
	 * 消息交付回调
	 */
	class RSendCallback : public SendCallback {
	private:
		std::function<void(SendStatus)> cf;
	public:
		explicit RSendCallback(std::function<void(SendStatus)> cf);
		void onSuccess(SendResult& sendResult) override;
		void onException(MQException& e) override;
	};
	/**
	 * 消费消息监听器
	 */
	class RConsumerListener {
	public:
		// 接收消息
		virtual void receiveMessage(std::string payload) = 0;
	};
private:
	// nameserver地址
	std::string namesrv;
	// 分组名称
	std::string groupname;
	// 当前主题
	std::string m_topic;
	// 接收消息事件通知集合
	std::vector<RConsumerListener*> m_listeners;
	// 生产者
	DefaultMQProducer* m_producer;
	// 消费者
	DefaultMQPushConsumer* m_consumer;
	// MQ消息监听器
	RMessageLisenter* m_msgListener;
	// 释放生产者
	void releaseProducer();
	// 释放消费者
	void releaseConsumer();
public:
	//************************************
	// Method:    RocketClient
	// FullName:  RocketClient::RocketClient
	// Access:    public 
	// Returns:   
	// Qualifier: 构造初始化
	// Parameter: const std::string & namesrv nameserver地址，如：ip1:port1;ip2:port2
	// Parameter: const std::string & groupName 分组名称，默认值为cpp-rocketmq
	//************************************
	explicit RocketClient(const std::string& namesrv, const std::string& groupName = "cpp-rocketmq");
	// 析构释放资源
	~RocketClient();
	//************************************
	// Method:    productMsg
	// FullName:  RocketClient::productMsg
	// Access:    public 
	// Returns:   void
	// Qualifier: 生产消息
	// Parameter: const std::string & topic 主题
	// Parameter: const std::string & body 消息主题
	// Parameter: SendCallback * cb 发送结果回调对象，默认值nullptr
	//************************************
	void productMsgAsync(const std::string& topic, const std::string& body, SendCallback* cb = nullptr);
	//************************************
	// Method:    productMsgSync
	// FullName:  RocketClient::productMsgSync
	// Access:    public 
	// Returns:   rocketmq::SendStatus 消息发送结果状态
	// Qualifier: 同步生产消息
	// Parameter: const std::string & topic 主题
	// Parameter: const std::string & body 消息主体
	//************************************
	rocketmq::SendStatus productMsgSync(const std::string& topic, const std::string& body);
	//************************************
	// Method:    subscribe
	// FullName:  RocketClient::subscribe
	// Access:    public 
	// Returns:   bool 订阅成功返回true
	// Qualifier: 订阅主题
	// 注意：同一个RocketClient对象只能订阅一次，当然你可以取消订阅，然后重新订阅
	// Parameter: const std::string & topic 主题
	//************************************
	bool subscribe(const std::string& topic);
	//************************************
	// Method:    unsubscribe
	// FullName:  RocketClient::unsubscribe
	// Access:    public 
	// Returns:   void
	// Qualifier: 取消订阅
	//************************************
	void unsubscribe();
	//************************************
	// Method:    addListener
	// FullName:  RocketClient::addListener
	// Access:    public 
	// Returns:   void
	// Qualifier: 添加订阅消息处理监听者
	// Parameter: RConsumerListener * listener 监听者对象
	//************************************
	void addListener(RConsumerListener* listener);
	//************************************
	// Method:    removeListener
	// FullName:  RocketClient::removeListener
	// Access:    public 
	// Returns:   void
	// Qualifier: 移除订阅消息处理监听者
	// Parameter: RConsumerListener * listener 监听者对象
	//************************************
	void removeListener(RConsumerListener* listener);
	//************************************
	// Method:    removeAllListener
	// FullName:  RocketClient::removeAllListener
	// Access:    public 
	// Returns:   void
	// Qualifier: 移除所有订阅消息处理监听者
	//************************************
	void removeAllListener();
};

#endif // _ROCKETCLIENT_H_
