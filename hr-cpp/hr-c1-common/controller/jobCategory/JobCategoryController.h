#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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


#ifndef _JOBCATEGORYCONTROLLER_H_
#define _JOBCATEGORYCONTROLLER_H_
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/vo/pullList/PullListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class JobCategoryController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(JobCategoryController);
public: // 定义接口
	ENDPOINT_INFO(queryJobCategory) {
		info->summary = ZH_WORDS_GETTER("common.controller.JobCategory");
		API_DEF_ADD_RSP_JSON_WRAPPER(PullListVO);
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, PATH_TO_PULLIST("/job-category"), queryJobCategory, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryJobCategory());
	}
private: // 定义接口执行函数
	PullListVO::Wrapper execQueryJobCategory();
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_#pragma once