#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 10:50:42
 
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
#ifndef _DB_INIT_
#define _DB_INIT_

#include "ConnectionPool.h"

/**
 * 数据库配置对象
 */
class DBConfig
{
public:
	// 用户名
	string user = "";
	// 密码
	string pass = "";
	// 数据库名
	string db = "";
	// 主机IP
	string host = "127.0.0.1";
	// 服务端端口
	int port = 3306;
	// 最大连接数
	int poolMaxSize = 25;
	DBConfig() {}
	DBConfig(string _user, string _pass, string _db, string _host, int _port, int _maxSize) :user(_user), pass(_pass), db(_db), host(_host), port(_port), poolMaxSize(_maxSize) {}
};

/**
 * 数据库初始化
 */
class DbInit final
{
private:
	// 单例对象
	static ConnPool* connPool;
public:
	//************************************
	// Method:    initDbPool
	// FullName:  DbInit::initDbPool
	// Access:    public static 
	// Returns:   bool 是否初始化成功
	// Qualifier: 初始化连接池
	// Parameter: DBConfig config 数据库配置对象
	//************************************
	static bool initDbPool(DBConfig config);

	//************************************
	// Method:    getConnPool
	// FullName:  DbInit::getConnPool
	// Access:    public static 
	// Returns:   ConnPool*
	// Qualifier: 获取连接池对象
	//************************************
	static ConnPool* getConnPool();

	//************************************
	// Method:    releasePool
	// FullName:  DbInit::releasePool
	// Access:    public static 
	// Returns:   void
	// Qualifier: 释放连接池
	//************************************
	static void releasePool();
};

#endif // !DB_INIT_