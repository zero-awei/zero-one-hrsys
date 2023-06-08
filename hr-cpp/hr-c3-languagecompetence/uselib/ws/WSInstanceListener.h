#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/09 21:46:33

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
#ifndef _WSINSTANCELISTENER_H_
#define _WSINSTANCELISTENER_H_
#include "oatpp-websocket/ConnectionHandler.hpp"
#include <map>

/**
 * 定义示例WS实例监听器
 */
class WSInstanceListener : public oatpp::websocket::ConnectionHandler::SocketInstanceListener
{
private:
	static constexpr const char* TAG = "Server_WSInstanceListener";
public:
	/**
	 * Counter for connected clients.
	 */
	static std::atomic<v_int32> SOCKETS;
	// 定义一个连接对象池
	std::map<std::string, const WebSocket*> conn_pool;
	// 定义一个锁对象
	std::mutex instance_mutex;
public:
	// 当socket实例创建时调用
	void onAfterCreate(const WebSocket& socket, const std::shared_ptr<const ParameterMap>& params) override;
	// 当socket实例销毁前调用
	void onBeforeDestroy(const WebSocket& socket) override;
};

#endif // !_WSINSTANCELISTENER_H_
#endif // HTTP_SERVER_DEMO