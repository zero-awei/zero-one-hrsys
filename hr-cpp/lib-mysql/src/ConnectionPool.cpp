/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 12:10:25
 
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
#include "../include/ConnectionPool.h"
#include <stdexcept>
#include <exception>
#include <stdio.h>

// 数据库连接池的构造函数
ConnPool::ConnPool(string url, string userName, string password, int maxSize)
{
	this->maxSize = maxSize;
	this->curSize = 0;
	this->username = userName;
	this->password = password;
	this->url = url;

	try
	{
		this->driver = sql::mysql::get_mysql_driver_instance();
	}
	catch (sql::SQLException& e)
	{
		printf("get driver error. msg=%s\n", e.what());
	}
	catch (std::runtime_error& e)
	{
		printf("[ConnPool] run time error. msg=%s\n", e.what());
	}

	// 在初始化连接池时，建立一定数量的数据库连接
	this->InitConnection(maxSize / 2);
}

// 初始化数据库连接池，创建最大连接数一半的连接数量
void ConnPool::InitConnection(int iInitialSize)
{
	Connection* conn;
	lock.lock();

	for (int i = 0; i < iInitialSize; i++)
	{
		conn = this->CreateConnection();
		if (conn)
		{
			connList.push_back(conn);
			++(this->curSize);
		}
		else
		{
			printf("Init connection<%d> error.\n", i + 1);
			break;
		}
	}

	lock.unlock();
}

// 创建并返回一个连接
Connection* ConnPool::CreateConnection()
{
	Connection* conn;
	try
	{
		// 建立连接
		conn = driver->connect(this->url, this->username, this->password);
		return conn;
	}
	catch (sql::SQLException& e)
	{
		printf("create connection error. msg=%s\n", e.what());
		return NULL;
	}
	catch (std::runtime_error& e)
	{
		printf("[CreateConnection] run time error. msg=%s\n", e.what());
		return NULL;
	}
}

// 从连接池中获得一个连接
Connection* ConnPool::GetConnection()
{
	Connection* con;
	lock.lock();

	// 连接池容器中还有连接
	if (connList.size() > 0)
	{
		// 获取第一个连接
		con = connList.front();
		// 移除第一个连接
		connList.pop_front();
		// 判断获取到的连接的可用性
		// 如果连接已经被关闭，删除后重新建立一个
		if (con->isClosed() || !con->isValid())
		{
			delete con;
			con = this->CreateConnection();
			// 如果连接为空，说明创建连接出错
			if (con == NULL)
			{
				// 从容器中去掉这个空连接
				--curSize;
			}
		}

		lock.unlock();
		return con;
	}
	// 连接池容器中没有连接
	else
	{
		// 当前已创建的连接数小于最大连接数，则创建新的连接
		if (curSize < maxSize)
		{
			con = this->CreateConnection();
			if (con)
			{
				++curSize;
				lock.unlock();
				return con;
			}
			else
			{
				lock.unlock();
				return NULL;
			}
		}
		// 当前建立的连接数已经达到最大连接数
		else
		{
			perror("[GetConnection] connections reach the max number. \n");
			lock.unlock();
			return NULL;
		}
	}
}

// 释放数据库连接，将该连接放回到连接池中
void ConnPool::ReleaseConnection(sql::Connection* conn)
{
	if (conn)
	{
		lock.lock();

		connList.push_back(conn);

		lock.unlock();
	}
}

// 数据库连接池的析构函数
ConnPool::~ConnPool()
{
	this->DestoryConnPool();
}

// 销毁连接池，需要先销毁连接池的中连接
void ConnPool::DestoryConnPool()
{
	list<Connection*>::iterator itCon;
	lock.lock();

	for (itCon = connList.begin(); itCon != connList.end(); ++itCon)
	{
		// 销毁连接池中的连接
		this->DestoryConnection(*itCon);
	}
	curSize = 0;

	// 清空连接池中的连接
	connList.clear();

	lock.unlock();
}

// 销毁数据库连接
void ConnPool::DestoryConnection(Connection* conn)
{
	if (conn)
	{
		try
		{
			// 关闭连接
			conn->close();
		}
		catch (sql::SQLException& e)
		{
			printf("%s\n", e.what());
		}
		catch (std::exception& e)
		{
			printf("%s\n", e.what());
		}
		// 删除连接
		delete conn;
	}
}