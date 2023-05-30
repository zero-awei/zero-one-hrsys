#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/08 21:23:08

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
#ifndef _CONTRACTCONTROLLER_H_
#define _CONTRACTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/contract/ContractQuery.h"
#include "domain/vo/contract/ContractVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * 合同查询控制器
 */
class ContractController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ContractController);
public: // 定义接口
	// 3 定义接口描述
	ENDPOINT_INFO(queryContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 添加其他查询参数
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("contract.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("105CB946-F5CF-4A8E-88D5-CFFA5B1B4A4C"));
	}
	// 4 定义接口端点
	ENDPOINT(API_M_GET,"/contract/select", queryContract, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ContractQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private: // 定义接口执行函数
	// 5 定义接口的执行函数
	ContractPageJsonVO::Wrapper execQueryTest(const ContractQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_CONTRACTCONTROLLER_H_