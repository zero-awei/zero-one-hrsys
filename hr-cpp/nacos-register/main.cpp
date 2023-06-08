/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:02:34

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
#include "StringUtil.h"
#include "ServerInfo.h"
#include "HttpServer.h"
#include "NacosClient.h"
#include <iostream>

/**
 * 解析启动参数
 * 注意：
 * 参数中数据需要满足一定的格式，如：sp=8090、sn=feign-cpp-sample
 * 前缀与真实值之间使用=分隔
 */
void getStartArg(int argc, char* argv[]) {
	// 服务器端口
	std::string serverPort = "8070";
	// Nacos配置参数
	std::string nacosAddr = "192.168.220.128:8848";
	std::string nacosNs = "4833404f-4b82-462e-889a-3c508160c6b4";
	std::string regFileId = "demo-nacos-cli";

	// 开始解析
	int currIndex = 1;
	bool isSetDb = false;
	while (currIndex < argc)
	{
		// 拆分字符串
		auto args = StringUtil::split(argv[currIndex], "=");
		// 判断参数是否合法
		if (args.size() != 2)
		{
			std::cout << "arg: " << argv[currIndex] << ", format error." << std::endl;
			exit(1);
		}

		// 根据参数前缀对不同属性赋值
		std::string prefix = args[0];
		std::string val = args[1];
		if (prefix == "sp") serverPort = val;
		else if (prefix == "na") nacosAddr = val;
		else if (prefix == "ns") nacosNs = val;
		else if (prefix == "fi") regFileId = val;
		// 更新索引
		currIndex++;
	}

	// 记录服务器配置到内存中方便使用
	ServerInfo::getInstance().setServerPort(serverPort);
	ServerInfo::getInstance().setNacosAddr(nacosAddr);
	ServerInfo::getInstance().setNacosNs(nacosNs);
	ServerInfo::getInstance().setNacosRegFileID(regFileId);
}

int main(int argc, char* argv[]) {
	// 服务器参数初始化
	getStartArg(argc, argv);

	// 创建Nacos客户端对象
	NacosClient nacosClient(
		ServerInfo::getInstance().getNacosAddr(),
		ServerInfo::getInstance().getNacosNs());

	// 读取配置
	auto configs = nacosClient.getConfig(ServerInfo::getInstance().getNacosRegFileID());

	// 注册服务
	for (auto one : configs)
	{
		nacosClient.registerInstance(one["ip"].as<string>(), one["port"].as<int>(), one["name"].as<string>());
	}

	// 启动HTTP服务器
	HttpServer::startServer(ServerInfo::getInstance().getServerPort(), [=](Endpoints* doc, HttpRouter* router) {});

	// 反注册服务
	for (auto one : configs)
	{
		nacosClient.deregisterInstance(one["ip"].as<string>(), one["port"].as<int>(), one["name"].as<string>());
	}
	return 0;
}
