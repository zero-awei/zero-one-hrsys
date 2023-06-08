#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
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
#ifndef _PAGEQUERYPROJTAGLISTCONTROELLER_H_
#define _PAGEQUERYPROJTAGLISTCONTROELLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/query/projTag/PageProjTagQuery.h"
#include "domain/vo/projTag/PageQueryProjTagVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
/**
 * 分页查询项目标签列表控制器
 * 负责人：咫尺之书
 * 对应数据表：t_ormxmbq
 */
class PageQueryProjTagListController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PageQueryProjTagListController);
public: // 定义接口
	ENDPOINT_INFO(pageQueryProjTag) {
		info->summary = ZH_WORDS_GETTER("projTag.pageQuery.controller");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(PageQueryProjTagVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "order", ZH_WORDS_GETTER("projTag.pageQuery.order"), "ASC", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tagName", ZH_WORDS_GETTER("projTag.pageQuery.tagName"), "tag1", false);
	}

	ENDPOINT(API_M_GET, PATH_TO_PROJTAG("/page-query-project-tag-list"), pageQueryProjTag, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, PageProjTagQuery, qps);
		API_HANDLER_RESP_VO(execPageQueryProjTag(query));
	}
private: // 定义接口执行函数
	PageQueryProjTagVO::Wrapper execPageQueryProjTag(const PageProjTagQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PAGEQUERYPROJTAGLISTCONTROELLER_H_