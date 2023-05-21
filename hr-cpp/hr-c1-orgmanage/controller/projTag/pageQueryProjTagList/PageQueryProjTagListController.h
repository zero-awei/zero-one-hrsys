#pragma once
#ifndef _PAGEQUERYPROJTAGLISTCONTROELLER_H_
#define _PAGEQUERYPROJTAGLISTCONTROELLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/query/projTag/PageProjTagQuery.h"
#include "domain/vo/pageQuery/PageQueryVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class PageQueryProjTagListController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(PageQueryProjTagListController);
public: // 定义接口
	ENDPOINT_INFO(pageQueryProjTag) {
		info->summary = ZH_WORDS_GETTER("projTag.pageQuery.controller");
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(PageQueryVO);
		//API_DEF_ADD_PAGE_PARAMS();
		info->queryParams.add<UInt8>("size").description = ZH_WORDS_GETTER("projTag.pageQuery.size");
		info->queryParams["size"].addExample("default", UInt8(20));
		info->queryParams["size"].required = true;
		info->queryParams.add<UInt8>("page").description = ZH_WORDS_GETTER("projTag.pageQuery.page");
		info->queryParams["page"].addExample("default", UInt8(1));
		info->queryParams["page"].required = true;
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("projTag.pageQuery.sort");
		info->queryParams["sort"].addExample("default", String("xh,ASC"));
		info->queryParams["sort"].required = true;
	}

	ENDPOINT(API_M_GET, "/project-tag/page-query-project-tag-list", pageQueryProjTag, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, PageProjTagQuery, qps);
		API_HANDLER_RESP_VO(execPageQueryProjTag(query));
	}
private: // 定义接口执行函数
	PageQueryVO::Wrapper execPageQueryProjTag(const PageProjTagQuery::Wrapper& Query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PAGEQUERYPROJTAGLISTCONTROELLER_H_