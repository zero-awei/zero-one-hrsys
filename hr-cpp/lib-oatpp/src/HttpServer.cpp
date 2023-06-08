/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/28 14:05:46

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
#include <iostream>
#include <signal.h>
#include "oatpp/network/Server.hpp"
#include "oatpp-swagger/Controller.hpp"
#include "../include/HttpServer.h"
#include "../include/AppComponent.hpp"

// 如果没有定义关闭服务器密码
#ifndef STOP_PWD
#define STOP_PWD "01star"
#endif

// 定义一个全局变量，设置是否让服务器运行
bool isAllowServerRun = true;

// 定义关闭请求控制器
#include OATPP_CODEGEN_BEGIN(ApiController)
class ServerCloseController : public oatpp::web::server::api::ApiController {
public:
	ServerCloseController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) :oatpp::web::server::api::ApiController(objectMapper) {}
	static std::shared_ptr<ServerCloseController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
	{
		return std::make_shared<ServerCloseController>(objectMapper);
	}
	ENDPOINT("GET", "/system-kill/{pwd}", closeServer, PATH(String, pwd)) {
		if (pwd == STOP_PWD)
		{
			isAllowServerRun = false;
			OATPP_LOGD("Server", "server stop ok");
			return createResponse(Status::CODE_200, "server will close \r\n");
		}
		return createResponse(Status::CODE_200, "password is not right \r\n");
	}
};
#include OATPP_CODEGEN_END(ApiController)

void HttpServer::initServer(string port, string host, function<void(Endpoints*, HttpRouter*)> bindRouterFun, function<void(std::shared_ptr<AbstractComponentReg>*)> otherComponentRegCall)
{
	// 注册环境组件
	AppComponent components;
	// 注册其它组件
	std::shared_ptr<AbstractComponentReg> other = nullptr;
	if (otherComponentRegCall)
	{
		otherComponentRegCall(&other);
	}

	// 创建监听端口的ConnectionProvider组件
	uint16_t currPort = (uint16_t)strtoul(port.c_str(), NULL, 0);
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)([=] {
		return oatpp::network::tcp::server::ConnectionProvider::createShared({ host, currPort, oatpp::network::Address::IP_4 });
		}());
	// 获取路由组件
	OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
	// 获取连接处理组件
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler, "http");
	// 获取连接提供组件
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);
	// 创建服务
	oatpp::network::Server server(connectionProvider, connectionHandler);
	// 打印服务器信息
	OATPP_LOGD("Server", "Running on port %s...", connectionProvider->getProperty("port").toString()->c_str());

	// 创建文档端点
	oatpp::web::server::api::Endpoints docEndpoints;
	// 初始化路由
	bindRouterFun(&docEndpoints, router.get());
	// 添加端点到控制器
	router->addController(oatpp::swagger::Controller::createShared(docEndpoints));
	// 添加一个关闭服务接口
	router->addController(ServerCloseController::createShared());
	OATPP_LOGD("Server", "Router init success");
	OATPP_LOGD("Server", "local api doc url is http://localhost:%s/swagger/ui", port.c_str());

	// 绑定交互信号监听（Ctrl + C）
	signal(SIGINT, [](int signum)
		{
			isAllowServerRun = false;
			OATPP_LOGD("Server", "server stop ok");
		});

	// 运行服务
	server.run([=] {return isAllowServerRun; });
}

void HttpServer::startServer(string port, function<void(Endpoints*, HttpRouter*)> bindRouterFun, function<void(std::shared_ptr<AbstractComponentReg>*)> otherComponentRegCall /*= nullptr*/, string host /*= "0.0.0.0"*/)
{
	oatpp::base::Environment::init();

	initServer(port, host, bindRouterFun, otherComponentRegCall);

	/* Print how many objects were created during app running, and what have left-probably leaked */
	/* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
	std::cout << std::endl << "Environment:" << std::endl;
	std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << std::endl;
	std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << std::endl;

	oatpp::base::Environment::destroy();
}
