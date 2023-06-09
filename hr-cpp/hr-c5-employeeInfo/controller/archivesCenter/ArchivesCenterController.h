#pragma once
#ifndef _ARCHIVES_CENTER_CONTROLLER_H_
#define _ARCHIVES_CENTER_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/archivesCenter/ArchivesCenterQuery.h"
#include "domain/vo/archivesCenter/ArchivesCenterVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

class ArchivesCenterController
	: public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ArchivesCenterController);
public: // 定义接口
	// 3 定义查询接口描述
	ENDPOINT_INFO(queryArchivesCenter) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archivesCenter.get.summary");
		// 定义默认授权参数
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesCenterPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 4 定义查询接口处理
	ENDPOINT(API_M_GET, "/archivesCenter/queryArchivesCenter", queryArchivesCenter, /*API_HANDLER_AUTH_PARAME,*/ QUERIES(QueryParams, qps)) {
		API_HANDLER_QUERY_PARAM(query, ArchivesCenterQuery, qps);
		API_HANDLER_RESP_VO(execQueryArchivesCenter(query/*, authObject->getPayload()*/));
	}
private:
	ArchivesCenterPageJsonVO::Wrapper execQueryArchivesCenter(const PageQuery::Wrapper& query);
};

#endif // !_ARCHIVES_CENTER_CONTROLLER_H_


