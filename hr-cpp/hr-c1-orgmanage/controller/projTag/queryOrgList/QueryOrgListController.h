#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/24 17:58:45

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
#ifndef _QUERYORGLISTCONTROLLER_H_
#define _QUERYORGLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "ApiHelper.h"
#include "domain/query/projTag/OrgListQuery.h"
#include "domain/vo/projTag/OrgListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 分页查询组织列表控制器
 * 负责人：Andrew
 * 对应数据表：
 */
class QueryOrgListController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QueryOrgListController);
public: // 定义接口
	ENDPOINT_INFO(queryOrgList) {
		info->summary = ZH_WORDS_GETTER("projTag.orgList.summary");
		API_DEF_ADD_RSP_JSON_WRAPPER(OrgListVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "order", ZH_WORDS_GETTER("projTag.orgList.order"), "ASC", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orgCode", ZH_WORDS_GETTER("projTag.orgList.orgCode"), "tag114514", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orgName", ZH_WORDS_GETTER("projTag.orgList.orgName"), "test tag", false);
		API_DEF_ADD_QUERY_PARAMS(String, "shortname", ZH_WORDS_GETTER("projTag.orgList.shortname"), "org114514", false);
	}

	ENDPOINT(API_M_GET, PATH_TO_PROJTAG("/query-org-page"), queryOrgList, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams,qps)) {
		API_HANDLER_QUERY_PARAM(query, OrgListQuery, qps);
		API_HANDLER_RESP_VO(execQueryOrgList(query));
	}
private: // 定义接口执行函数
	OrgListVO::Wrapper execQueryOrgList(const OrgListQuery::Wrapper &query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUERYORGLISTCONTROLLER_H_