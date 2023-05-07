#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/24 15:53:42

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
#ifndef _ERRORHANDLER_H_
#define _ERRORHANDLER_H_

#include "oatpp/web/server/handler/ErrorHandler.hpp"
#include "oatpp/web/protocol/http/outgoing/ResponseFactory.hpp"

/**
 * 声明一个错误信息处理器
 */
class ErrorHandler : public oatpp::web::server::handler::ErrorHandler
{
private:
	typedef oatpp::web::protocol::http::outgoing::Response OutgoingResponse;
	typedef oatpp::web::protocol::http::Status Status;
	typedef oatpp::web::protocol::http::outgoing::ResponseFactory ResponseFactory;
private:
	std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_objectMapper;
public:
	// 构造的时候传入数据序列化对象
	ErrorHandler(const std::shared_ptr<oatpp::data::mapping::ObjectMapper>& objectMapper);
	// 响应错误信息内容
	std::shared_ptr<OutgoingResponse> handleError(const Status& status, const oatpp::String& message, const Headers& headers) override;
};

#endif // _ERRORHANDLER_H_