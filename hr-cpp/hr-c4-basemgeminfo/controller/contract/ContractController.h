#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/14 22:43:38

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
#include "domain/query/contract/ContractQuery.h"
#include "domain/dto/contract/ContractDTO.h"
#include "domain/vo/contract/ContractVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ContractController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ContractController);
public: // 定义接口
	ENDPOINT_INFO(queryContract) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("contract.get.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ContractPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
	}
	ENDPOINT(API_M_GET, "/contract", queryContract, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(contractQuery, ContractQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryContract(contractQuery));
	}
private: // 定义接口执行函数
	ContractPageJsonVO::Wrapper execQueryContract(const ContractQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_CONTRACTCONTROLLER_H_