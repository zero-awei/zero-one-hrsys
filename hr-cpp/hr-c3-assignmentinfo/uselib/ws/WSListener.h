#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/09 21:53:07

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
#ifdef HTTP_SERVER_DEMO

#ifndef _WSLISTENER_H_
#define _WSLISTENER_H_
#include "oatpp-websocket/WebSocket.hpp"
#include "oatpp-websocket/ConnectionHandler.hpp"
#include <map>

/**
 * WebSocket侦听器,侦听传入的WebSocket事件
 */
class WSListener : public oatpp::websocket::WebSocket::Listener
{
private:
	static constexpr const char* TAG = "Server_WSListener";
	// 消息缓冲区
	oatpp::data::stream::BufferOutputStream m_messageBuffer;
	// 用户ID
	std::string id;
	// 加入聊天室用户列表
	std::map<std::string, const WebSocket*>* conn_pool;
public:
	// 获取ID
	const std::string& getId();
	// 构造初始化
	WSListener(std::string id, std::map<std::string, const WebSocket*>* conn_pool);
	// 在ping帧上调用
	void onPing(const WebSocket& socket, const oatpp::String& message) override;
	// 在pong帧上调用
	void onPong(const WebSocket& socket, const oatpp::String& message) override;
	// 在close帧上调用
	void onClose(const WebSocket& socket, v_uint16 code, const oatpp::String& message) override;
	// 在每个消息帧上调用。最后一条消息将再次调用，size等于0以指定消息结束
	void readMessage(const WebSocket& socket, v_uint8 opcode, p_char8 data, oatpp::v_io_size size) override;
};

#endif // !_WSLISTENER_H_

#endif // HTTP_SERVER_DEMO