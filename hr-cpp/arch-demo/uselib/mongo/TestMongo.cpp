/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/18 16:55:21

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
#include "TestMongo.h"
#include "NacosClient.h"
#include "ServerInfo.h"
#include "YamlHelper.h"
#include "MongoClient.h"
#include <iostream>
#include <bsoncxx/json.hpp>

void TestMongo::testUseMongo()
{
	//获取配置
	NacosClient nacosClient(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif
	//获取mongodb相关配置
	YamlHelper yaml;
	string uri = yaml.getString(&node, "spring.data.mongodb.uri");

	//创建连接对象
	MongoClient mc(uri);

	//添加单条数据
	auto docBuilder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc = docBuilder
		<< "name" << "MongoDB"
		<< "type" << "database"
		<< "count" << 1
		<< "versions" << open_array
		<< "v3.2" << "v3.0" << "v2.6"
		<< close_array
		<< "info" << open_document
		<< "x" << 203
		<< "y" << 102
		<< close_document
		<< finalize;
	auto res = mc.addOne("t1", doc.view());
	if (res.type() != bsoncxx::type::k_null)
	{
		std::cout << res.get_oid().value.to_string() << std::endl;
	}

	//添加多条数据
	std::vector<bsoncxx::document::value> documents;
	for (int i = 0; i < 10; i++) {
		documents.push_back(bsoncxx::builder::stream::document{} << "i" << i << finalize);
	}
	int32_t addNum = mc.addMultiple("t2", documents);
	cout << "add data:" << addNum << endl;

	//执行查询调用
	mc.execute("t2",
		[](mongocxx::collection* collection) {
			auto cursor = collection->find({});
			for (auto doc : cursor) {
				cout << bsoncxx::to_json(doc) << endl;
			}
		});
}
