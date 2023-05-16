#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/16 14:48:37

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
#ifndef _LEGALENTITYMAICONTROLLER_H_
#define _LEGALENTITYMAICONTROLLER_H_

#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/LegalEntityMai/LegalEntityMaiVO.h"

using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)

/* 法人主体维护，控制器*/
class LegalEntityMaiController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(LegalEntityMaiController);
public: // 定义接口
	// 定义查询法人主体信息接口端点描述
	ENDPOINT_INFO(queryLegalEntityMai) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("LegalEntityMai.query.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(LegalEntityMaiPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		info->queryParams.add<String>("ORMSIGNORGID").description = ZH_WORDS_GETTER("LegalEntityMai.field.id");
		info->queryParams["ORMSIGNORGID"].addExample("default", String("1"));
	}
	// 定义查询法人主体信息接口端点处理
	ENDPOINT(API_M_GET, "/LegalEntityMai", queryLegalEntityMai, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(legalEntityMaiQuery, LegalEntityMaiQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(executeQueryById(legalEntityMaiQuery));
	}
private: // 定义接口执行函数
	// 通过id查询
	LegalEntityMaiPageJsonVO::Wrapper executeQueryById(const LegalEntityMaiQuery::Wrapper& legalEntityMaiQuery);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_LEGALENTITYMAICONTROLLER_H_