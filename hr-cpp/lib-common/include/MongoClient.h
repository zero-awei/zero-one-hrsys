#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/17 20:47:04

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
#ifndef _MONGOCLIENT_H_
#define _MONGOCLIENT_H_
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <string>
#include <memory>
#include <functional>
using namespace std;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::finalize;

/**
 * MongoDB客户端
 */
class MongoClient
{
private:
	// 用户名
	string m_username;
	// 密码
	string m_password;
	// MongoDB服务器地址
	string m_host;
	// 数据库
	string m_db;
	// MongoDB服务器端口
	string m_port;
	// 最大连接数
	int m_max = 25;
	// 最小连接数据
	int m_min = 25;
	// 标记是否已经初始化
	bool isInit;
	// 负责构造和析构连接驱动的实例对象
	mongocxx::instance m_inst;
	// 连接池对象
	shared_ptr<mongocxx::pool> m_pool;
	// 初始化连接池
	bool initPool();
public:
	//************************************
	// Method:    MongoClient
	// FullName:  MongoClient::MongoClient
	// Access:    public 
	// Returns:   
	// Qualifier: 构造初始化
	// Parameter: const string & username 用户名
	// Parameter: const string & password 密码
	// Parameter: const string & host 服务器地址
	// Parameter: const string & db 数据库
	// Parameter: const string & port 服务器端口，默认值27017
	//************************************
	MongoClient(const string& username, const string& password, const string& host, const string& db, const string& port = "27017");
	//************************************
	// Method:    MongoClient
	// FullName:  MongoClient::MongoClient
	// Access:    public 
	// Returns:   
	// Qualifier: 构造初始化
	// Parameter: const string & uri 连接地址，格式为：mongodb://账号:密码@主机地址:端口/数据库名称
	//************************************
	explicit MongoClient(const string& uri);
	// 设置最大连接数
	void setMax(int max);
	// 设置最小连接数
	void setMin(int min);
	//************************************
	// Method:    execute
	// FullName:  MongoClient::execute
	// Access:    public 
	// Returns:   bool
	// Qualifier: 定义一个执行方法，用于支持操作扩展
	// Parameter: const string & collectionName 集合名称
	// Parameter: std::function<void mongocxx::collection*> callfun 扩展执行回调函数
	//************************************
	bool execute(const string& collectionName, std::function<void(mongocxx::collection*)> callfun);
	//************************************
	// Method:    addOne
	// FullName:  MongoClient::addOne
	// Access:    public 
	// Returns:   bsoncxx::types::bson_value::view
	// Qualifier: 添加一条数据
	// Parameter: const string & collectionName 集合名称
	// Parameter: const bsoncxx::document::view & document 文档对象
	//************************************
	bsoncxx::types::bson_value::view addOne(const string& collectionName, const bsoncxx::document::view& document);
	//************************************
	// Method:    addMultiple
	// FullName:  MongoClient::addMultiple
	// Access:    public 
	// Returns:   int32_t 插入数据条数
	// Qualifier: 添加多条数据
	// Parameter: const string & collectionName 集合名称
	// Parameter: const std::vector<bsoncxx::document::value> & documents 文档对象列表
	//************************************
	int32_t addMultiple(const string& collectionName, const std::vector<bsoncxx::document::value>& documents);
};

#endif // _MONGOCLIENT_H_