#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/09 22:18:39

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
#ifndef _WSCONTROLLER_H_
#define _WSCONTROLLER_H_
#include "ApiHelper.h"
#include "oatpp-websocket/Handshaker.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- codegen begin
/**
 * 测试WebSocket访问端点创建
 */
class WSContorller : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(WSContorller);
private:
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, websocketConnectionHandler, "websocket");
public:
	ENDPOINT(API_M_GET, "chat", chat, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		auto response = oatpp::websocket::Handshaker::serversideHandshake(request->getHeaders(), websocketConnectionHandler);
		auto parameters = std::make_shared<oatpp::network::ConnectionHandler::ParameterMap>();
		(*parameters)["id"] = request->getQueryParameter("id");
		response->setConnectionUpgradeParameters(parameters);
		return response;
	};
};
#include OATPP_CODEGEN_END(ApiController) //<-- codegen begin
#endif // !_WSCONTROLLER_H_