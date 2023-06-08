#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/20 15:29:33

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
#ifndef _UPDATEPROJTAGCONTROLLER_H_
#define _UPDATEPROJTAGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/dto/projTag/ModifyTagDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ModifyProjTagController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyProjTagController);
public: // 定义接口
	ENDPOINT_INFO(modifyProjTag) {
		info->summary = ZH_WORDS_GETTER("projTag.modify.summary");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		/*API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("projTag.field.id"), "tag114514", true);
		API_DEF_ADD_QUERY_PARAMS(String, "tagName", ZH_WORDS_GETTER("projTag.field.tagName"), "test tag", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orgId", ZH_WORDS_GETTER("projTag.field.orgId"), "org114514", false);
		API_DEF_ADD_QUERY_PARAMS(String, "updater", ZH_WORDS_GETTER("projTag.field.updater"), "root", false);
		API_DEF_ADD_QUERY_PARAMS(String, "updateTime", ZH_WORDS_GETTER("projTag.field.updateTime"), "2000-01-01 24:00:00", false);*/
	}

	ENDPOINT(API_M_PUT, PATH_TO_PROJTAG("/modify-project-tag"), modifyProjTag, API_HANDLER_AUTH_PARAME, BODY_DTO(ModifyTagDTO::Wrapper, dto)) {
		API_HANDLER_RESP_VO(execModifyTag(dto, authObject->getPayload()));
	}
private: // 定义接口执行函数
	StringJsonVO::Wrapper execModifyTag(const ModifyTagDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_UPDATEPROJTAGCONTROLLER_H_