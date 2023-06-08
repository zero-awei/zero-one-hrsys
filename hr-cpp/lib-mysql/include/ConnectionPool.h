#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 10:50:30
 
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
#ifndef __CONNECTION_POOL_H__
#define __CONNECTION_POOL_H__

#include "./mysql/jdbc.h"
#include <list>
#include <string>
#include <mutex>

using namespace std;
using namespace sql;
/**
 * 定义一个数据库连接池类
 */
class ConnPool final
{
public:
	// 构造初始化
	ConnPool(string url, string user, string password, int maxSize);
	// 析构释放内存
	~ConnPool();
	// 获取数据库连接
	Connection* GetConnection();
	// 将数据库连接放回到连接池的容器中
	void ReleaseConnection(Connection* conn);
private:
	// 当前已建立的数据库连接数量
	int curSize;
	// 连接池定义的最大数据库连接数
	int maxSize;
	// 用户名
	string username;
	// 密码
	string password;
	// 连接地址：如tcp://localhost:3306/db
	string url;
	// 连接驱动对象
	Driver* driver;
	// 连接池容器
	list<Connection*> connList;
	// 线程锁
	mutex lock;
	
	// 创建一个连接
	Connection* CreateConnection();
	// 初始化数据库连接池
	void InitConnection(int iInitialSize);
	// 销毁数据库连接对象
	void DestoryConnection(Connection* conn);
	// 销毁数据库连接池
	void DestoryConnPool();
};

#endif /*_CONNECTION_POOL_H */
