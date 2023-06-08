#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/21 16:47:50

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
#ifndef _REDISCLIENT_H_
#define _REDISCLIENT_H_
#include <string>
#include <memory>
#include <iostream>
#include <functional>
#include "sw/redis++/redis++.h"
using namespace std;
using namespace sw::redis;

/**
 * Redis客户端
 */
class RedisClient
{
private:
	// Redis连接对象
	shared_ptr<Redis> m_redis;
public:
	//************************************
	// Method:    RedisClient
	// FullName:  RedisClient::RedisClient
	// Access:    public 
	// Returns:   
	// Qualifier: 构造初始化
	// Parameter: const string & host Redis主机地址
	// Parameter: int port Redis服务器端口
	// Parameter: const string & password Redis服务器密码,默认没有密码
	// Parameter: int db 选择的数据库，默认值0
	// Parameter: int max 数据库最大连接数，默认为10
	//************************************
	RedisClient(const string& host, int port, const string& password = "", int db = 0, int max = 10);
	//************************************
	// Method:    execute
	// FullName:  RedisClient::execute
	// Access:    public 
	// Returns:   T 返回值类型
	// Qualifier: 执行Redis操作
	// Parameter: std::function<T<Redis*>> callfun 操作逻辑函数，所有操作逻辑函数在这里写
	//************************************
	template<class T>
	T execute(std::function<T(Redis*)> callfun)
	{
		try
		{
			return callfun(m_redis.get());
		}
		catch (const std::exception& e)
		{
			cerr << e.what() << endl;
		}
		return {};
	}
};

#endif // _REDISCLIENT_H_