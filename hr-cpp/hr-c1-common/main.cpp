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
#include "stdafx.h"
#include "StringUtil.h"
#include "ServerInfo.h"
#include "HttpServer.h"
#include "controller/Router.h"
#include "controller/OtherComponent.hpp"
#include "DbInit.h"
//#ifdef HTTP_SERVER_DEMO
//#include "uselib/jwt/TestToken.h"
//#endif

#ifdef USE_NACOS
#include "NacosClient.h"
#include "YamlHelper.h"
#endif

bool getStartArg(int argc, char* argv[]) {
	// 服务器端口
	std::string serverPort = "8090";
	// 数据库连接信息
	std::string dbUsername = "root";
	std::string dbPassword = "123456";
	std::string dbName = "test";
	std::string dbHost = "127.0.0.1";
	int dbPort = 3060;
	int dbMax = 25;
#ifdef USE_NACOS

	std::string nacosAddr = "192.168.220.128:8848";
	std::string nacosNs = "4833404f-4b82-462e-889a-3c508160c6b4";
	std::string serviceName = "feign-cpp-sample";
	std::string regIp = "192.168.220.128";
#endif

	int currIndex = 1;
	bool isSetDb = false;
	while (currIndex < argc)
	{

		auto args = StringUtil::split(argv[currIndex], "=");
		if (args.size() != 2)
		{
			cout << "arg: " << argv[currIndex] << ", format error." << endl;
			exit(1);
		}
		std::string prefix = args[0];
		std::string val = args[1];
		if (prefix == "sp") serverPort = val;
		else if (prefix == "du")
		{
			isSetDb = true;
			dbUsername = val;
		}
		else if (prefix == "dp")
		{
			isSetDb = true;
			dbPassword = val;
		}
		else if (prefix == "dn")
		{
			isSetDb = true;
			dbName = val;
		}
		else if (prefix == "dh")
		{
			isSetDb = true;
			dbHost = val;
		}
		else if (prefix == "dP")
		{
			isSetDb = true;
			dbPort = atoi(val.c_str());
		}
		else if (prefix == "dm") dbMax = atoi(val.c_str());
#ifdef USE_NACOS
		else if (prefix == "na") nacosAddr = val;
		else if (prefix == "ns") nacosNs = val;
		else if (prefix == "sn") serviceName = val;
		else if (prefix == "ip") regIp = val;
#endif

		currIndex++;
	}

	ServerInfo::getInstance().setServerPort(serverPort);
	ServerInfo::getInstance().setDbUsername(dbUsername);
	ServerInfo::getInstance().setDbPassword(dbPassword);
	ServerInfo::getInstance().setDbName(dbName);
	ServerInfo::getInstance().setDbHost(dbHost);
	ServerInfo::getInstance().setDbPort(dbPort);
	ServerInfo::getInstance().setDbMax(dbMax);
#ifdef USE_NACOS
	ServerInfo::getInstance().setNacosAddr(nacosAddr);
	ServerInfo::getInstance().setNacosNs(nacosNs);
	ServerInfo::getInstance().setRegIp(regIp);
	ServerInfo::getInstance().setServiceName(serviceName);
#endif
	return isSetDb;
}

int main(int argc, char* argv[]) {
#ifdef HTTP_SERVER_DEMO
	TestToken::generateToken();
#endif


	bool isSetDb = getStartArg(argc, argv);

#ifdef USE_NACOS

	NacosClient nacosClient(
		ServerInfo::getInstance().getNacosAddr(),
		ServerInfo::getInstance().getNacosNs());

	if (!isSetDb)
	{
#ifdef LINUX
		YAML::Node node = nacosClient.getConfig("data-source.yaml");
#else
		YAML::Node node = nacosClient.getConfig("./conf/data-source.yaml");
#endif
		YamlHelper yaml;
		std::string dbUrl = yaml.getString(&node, "spring.datasource.url");
		if (dbUrl != "") {
			int dbPort = 0;
			std::string dbHost = "";
			std::string dbName = "";

			yaml.parseDbConnUrl(dbUrl, &dbHost, &dbPort, &dbName);

			std::string dbUsername = yaml.getString(&node, "spring.datasource.username");
			std::string dbPassword = yaml.getString(&node, "spring.datasource.password");

			ServerInfo::getInstance().setDbUsername(dbUsername);
			ServerInfo::getInstance().setDbPassword(dbPassword);
			ServerInfo::getInstance().setDbName(dbName);
			ServerInfo::getInstance().setDbHost(dbHost);
			ServerInfo::getInstance().setDbPort(dbPort);
		}
	}
	nacosClient.registerInstance(
		ServerInfo::getInstance().getRegIp(),
		atoi(ServerInfo::getInstance().getServerPort().c_str()),
		ServerInfo::getInstance().getServiceName());
#endif

	bool initConnPool = DbInit::initDbPool(DBConfig(
		ServerInfo::getInstance().getDbUsername(),
		ServerInfo::getInstance().getDbPassword(),
		ServerInfo::getInstance().getDbName(),
		ServerInfo::getInstance().getDbHost(),
		ServerInfo::getInstance().getDbPort(),
		ServerInfo::getInstance().getDbMax()));
	if (!initConnPool) return -1;

	HttpServer::startServer(ServerInfo::getInstance().getServerPort(),
		[=](Endpoints* doc, HttpRouter* router) {
			Router(doc, router).initRouter();
		},
		[](std::shared_ptr<AbstractComponentReg>* o) {
			*o = std::make_shared<OtherComponent>();
		});


	DbInit::releasePool();

#ifdef USE_NACOS

	nacosClient.deregisterInstance(
		ServerInfo::getInstance().getRegIp(),
		atoi(ServerInfo::getInstance().getServerPort().c_str()),
		ServerInfo::getInstance().getServiceName());
#endif
	return 0;
}
