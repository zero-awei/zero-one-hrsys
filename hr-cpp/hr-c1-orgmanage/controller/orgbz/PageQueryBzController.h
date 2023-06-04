#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/24 0:15:41

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
#ifndef _PAGEQUERYBZCONTROLLER_H_
#define _PAGEQUERYBZCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/query/orgbz/PageBzQuery.h"
#include "domain/vo/orgbz/PageQueryBzVO.h"
#include "domain/dto/orgbz/PageQueryBzDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PageQueryBzController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PageQueryBzController);
public: // 定义接口
	ENDPOINT_INFO(pageQueryBz) {
		info->summary = ZH_WORDS_GETTER("orgbz.pagequery.controller");
		API_DEF_ADD_RSP_JSON_WRAPPER(PageQueryBzVO);
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "orgName", ZH_WORDS_GETTER("orgbz.pagequery.orgname"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orgSectorName", ZH_WORDS_GETTER("orgbz.pagequery.orgsectorname"), "", false);
	}
	ENDPOINT(API_M_GET, PATH_TO_STAFFING("/query-bz"), pageQueryBz, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(Query, PageQueryBzQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execPageQueryBz(Query));
	}
private: // 定义接口执行函数
	PageQueryBzVO::Wrapper execPageQueryBz(const PageQueryBzQuery::Wrapper& Query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PAGEQUERYBZCONTROLLER_H_