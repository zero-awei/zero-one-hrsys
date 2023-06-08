/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/21 22:56:44

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
#include "../include/RedisClient.h"

RedisClient::RedisClient(const string& host, int port, const string& password /*= ""*/, int db /*= 0*/, int max /*= 10*/)
{
	// 定义连接信息
	ConnectionOptions co;
	co.host = host;
	co.port = port;
	co.db = db;
	if (password != "")
		co.password = password;

	// 定义连接池信息
	ConnectionPoolOptions po;
	po.size = max;
	po.wait_timeout = std::chrono::milliseconds(12);

	// 定义连接对象
	m_redis = make_shared<Redis>(co, po);
}