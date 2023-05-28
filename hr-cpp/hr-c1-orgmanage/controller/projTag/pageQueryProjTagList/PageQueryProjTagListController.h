#pragma once
#ifndef _PAGEQUERYPROJTAGLISTCONTROELLER_H_
#define _PAGEQUERYPROJTAGLISTCONTROELLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/query/projTag/PageProjTagQuery.h"
#include "domain/vo/projTag/PageQueryProjTagVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

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

	ENDPOINT(API_M_GET, "/project-tag/page-query-project-tag-list", pageQueryProjTag, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, PageProjTagQuery, qps);
		API_HANDLER_RESP_VO(execPageQueryProjTag(query));
	}
private: // 定义接口执行函数
	PageQueryProjTagVO::Wrapper execPageQueryProjTag(const PageProjTagQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PAGEQUERYPROJTAGLISTCONTROELLER_H_