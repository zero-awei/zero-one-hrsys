/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:17:46

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
#include "TestRedis.h"
#include "NacosClient.h"
#include "ServerInfo.h"
#include "YamlHelper.h"
#include "RedisClient.h"

void TestRedis::testUseRedis()
{
	//获取配置
	NacosClient nacosClient(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
#ifdef LINUX
	YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
	YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif
	
	//获取redis相关配置
	YamlHelper yaml;
	string host = yaml.getString(&node, "spring.redis.host");
	string port = yaml.getString(&node, "spring.redis.port");
	string password = yaml.getString(&node, "spring.redis.password");

	//创建RedisClient对象
	RedisClient rc(host, atoi(port.c_str()), password);

	//添加值
	bool res = rc.execute<bool>(
		[](Redis* r) {
			return r->set("foo", "bar");
		});
	std::cout << res << std::endl;
	//获取值
	string val = rc.execute<string>(
		[](Redis* r) {
			return r->get("foo").value();
		});
	std::cout << val << std::endl;
}
