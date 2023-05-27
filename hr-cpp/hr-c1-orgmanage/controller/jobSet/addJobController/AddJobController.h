#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/27 10:04:04

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
#ifndef _ADDJOBCONTROLLER_H_
#define _ADDJOBCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "ApiHelper.h"
#include "domain/dto/addJob/AddJobDTO.h"
#include "domain/dto/PayloadDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 岗位设置 - 新增岗位
 * 负责人：Andrew
 */
class AddJobController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(AddJobController);
public: // 定义接口
	ENDPOINT_INFO(addJob) {
		info->summary = ZH_WORDS_GETTER("jobSet.add.controller");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}

	ENDPOINT(API_M_POST, PATH_TO_JOBSET("/add-job"), addJob, API_HANDLER_AUTH_PARAME, BODY_DTO(AddJobDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddJob(dto, authObject->getPayload()));
	}
private: // 定义接口执行函数
	StringJsonVO::Wrapper execAddJob(const AddJobDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ADDJOBCONTROLLER_H_