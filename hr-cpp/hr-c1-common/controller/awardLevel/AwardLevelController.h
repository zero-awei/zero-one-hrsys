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


#ifndef _AwardLevelCONTROLLER_H_
#define _AwardLevelCONTROLLER_H_
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/awardLevel/AwardLevelQuery.h"
#include "domain/vo/awardLevel/AwardLevelVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class AwardLevelController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AwardLevelController);
public: // 定义接口
	// 3 定义接口描述
	ENDPOINT_INFO(queryAwardLevel) {
		// 定义接口标题
		info->summary = "award query";
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(AwardLevelPageJsonVO);
		// 定义分页查询参数描述
	}
	// 4 定义接口端点
	ENDPOINT(API_M_GET, "/test", queryAwardLevel, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query,	AwardLevelQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryAwardLevel(query));
	}
private: // 定义接口执行函数
	// 5 定义接口的执行函数
	AwardLevelPageJsonVO::Wrapper execQueryAwardLevel(const AwardLevelQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_