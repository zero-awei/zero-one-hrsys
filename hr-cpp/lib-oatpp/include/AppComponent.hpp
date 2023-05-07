#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/24 15:34:00

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
#ifndef _APPCOMPONENT_HPP_
#define _APPCOMPONENT_HPP_

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "SwaggerComponent.hpp"
#include "ErrorHandler.h"
#include "SystemInterceptor.h"

/**
 * 在oatpp::base::Environment中创建和保存Application组件，并完成组件注册
 * 组件初始化的顺序是从上到下
 */
class AppComponent
{
public:
	// 创建渲染接口文档的Swagger组件
	SwaggerComponent swaggerComponent;
	// 创建路由组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)([] {
		return oatpp::web::server::HttpRouter::createShared();
		}());
	// 创建ObjectMapper组件以在Controller的API中序列化/反序列化DTO
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)([] {
		auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
		objectMapper->getDeserializer()->getConfig()->allowUnknownFields = false;
		return objectMapper;
		}());
	// 创建使用Router组件路由http请求的ConnectionHandler组件
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, httpConnectionHandler)("http", [] {
		OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
		OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);
		// 创建一个连接处理器
		auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);
		// 添加通用错误处理器
		connectionHandler->setErrorHandler(std::make_shared<ErrorHandler>(objectMapper));
		// 添加跨域请求拦截器
		connectionHandler->addRequestInterceptor(std::make_shared<CrosRequestInterceptor>());
		// 添加跨域响应拦截器
		connectionHandler->addResponseInterceptor(std::make_shared<CrosResponseInterceptor>());
		// 添加校验请求拦截器
		connectionHandler->addRequestInterceptor(std::make_shared<CheckRequestInterceptor>(objectMapper));
		return connectionHandler;
		}());
};

#endif // _APPCOMPONENT_HPP_