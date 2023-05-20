/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/10 21:57:03

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
#include "stdafx.h"
#ifdef HTTP_SERVER_DEMO
#include "WSListener.h"
#include "StringUtil.h"

// 定义一个锁对象
std::mutex listener_mutex;

const std::string& WSListener::getId()
{
	return this->id;
}

WSListener::WSListener(std::string id, std::map<std::string, const WebSocket*>* conn_pool)
{
	this->id = id;
	this->conn_pool = conn_pool;
}

void WSListener::onPing(const WebSocket& socket, const oatpp::String& message)
{
	OATPP_LOGD(TAG, "onPing");
	socket.sendPong(message);
}

void WSListener::onPong(const WebSocket& socket, const oatpp::String& message)
{
	OATPP_LOGD(TAG, "onPong");
}

void WSListener::onClose(const WebSocket& socket, v_uint16 code, const oatpp::String& message)
{
	OATPP_LOGD(TAG, "onClose code=%d", code);
}

void WSListener::readMessage(const WebSocket& socket, v_uint8 opcode, p_char8 data, oatpp::v_io_size size)
{
	// message transfer finished
	if (size == 0)
	{
		// 获取消息数据
		auto wholeMessage = m_messageBuffer.toString().getValue("");
		m_messageBuffer.setCurrentPosition(0);
		OATPP_LOGD(TAG, "onMessage message='%s'", wholeMessage.c_str());
		// 解析消息 => ID::消息内容
		std::vector<string> msgs = StringUtil::split(wholeMessage.c_str(), "::");
		// 群发消息ID=all表示群发
		if ("all" == msgs[0])
		{
			std::lock_guard<std::mutex> guard(listener_mutex);
			for (auto one : *conn_pool)
			{
				// 排除自己
				if (one.second == &socket)
				{
					continue;
				}
				// 发送消息
				one.second->sendOneFrameText(msgs[1]);
			}
		}
		// 指定发送
		else
		{
			std::lock_guard<std::mutex> guard(listener_mutex);
			auto iter = conn_pool->find(msgs[0]);
			if (iter != conn_pool->end())
			{
				iter->second->sendOneFrameText(msgs[1]);
			}
		}
		socket.sendOneFrameText("message send success");
	}
	// message frame received
	else if (size > v_int64(0))
	{
		m_messageBuffer.writeSimple(data, v_buff_size(size));
	}
}

#endif // HTTP_SERVER_DEMO