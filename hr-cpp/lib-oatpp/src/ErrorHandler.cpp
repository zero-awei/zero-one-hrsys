/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/05 22:01:30

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
#include "../include/ErrorHandler.h"
#include "../include/domain/vo/JsonVO.h"
#include "../include/Message.h"

ErrorHandler::ErrorHandler(const std::shared_ptr<oatpp::data::mapping::ObjectMapper>& objectMapper)
	: m_objectMapper(objectMapper)
{

}

std::shared_ptr<ErrorHandler::OutgoingResponse>
ErrorHandler::handleError(const Status& status, const oatpp::String& message, const Headers& headers)
{
	auto error = NoDataJsonVO::createShared();
	Status currstatus = status;
	if (message->find("Token:") == 0) {
		currstatus = Status::CODE_200;
		error->init(RS_UNAUTHORIZED);
	}
	else
		error->init(RS_SERVER_ERROR);
	error->message = message;
	auto response = ResponseFactory::createResponse(currstatus, error, m_objectMapper);
	for (const auto& pair : headers.getAll()) {
		response->putHeader(pair.first.toString(), pair.second.toString());
	}
	return response;
}
