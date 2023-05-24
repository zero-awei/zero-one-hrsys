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
#include "domain/vo/pageQuery/PageQueryVO.h"
//去定义query,vo

#include OATPP_CODEGEN_BEGIN(ApiController)

class PageQueryBzController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PageQueryBzController);
public: // 定义接口
	ENDPOINT_INFO(pageQueryBz) {
		info->summary = ZH_WORDS_GETTER("orgbz.pagequery.controller");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(PageQueryVO);
		info->queryParams.add<UInt8>("size").description = ZH_WORDS_GETTER("orgbz.pagequery.size");
		info->queryParams["size"].addExample("default", UInt8(20));
		info->queryParams["size"].required = true;
		info->queryParams.add<UInt8>("page").description = ZH_WORDS_GETTER("orgbz.pagequery.page");
		info->queryParams["page"].addExample("default", UInt8(1));
		info->queryParams["page"].required = true;
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("orgbz.pagequery.sort");
		info->queryParams["sort"].addExample("default", String("xh,ASC"));
		info->queryParams["sort"].required = true;
	}
	ENDPOINT(API_M_GET, "/query-bz", pageQueryBz, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(query, PageBzQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execPageQueryBz(query));
	}
private: // 定义接口执行函数
	PageQueryVO::Wrapper execPageQueryBz(const PageBzQuery::Wrapper& Query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PAGEQUERYBZCONTROLLER_H_