#pragma once
#ifndef _ARCHIVESCONTROLLER_H_
#define _ARCHIVESCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/vo/archives/ArchivesVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * 档案查询控制器
 */
class ArchivesController :public oatpp::web::server::api::ApiController {//1
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ArchivesController);
public://定义接口
	// 3 定义接口描述
	ENDPOINT_INFO(queryArchives) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("archives.get.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ArchivesPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 添加其他查询参数
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["pimpersonid"].addExample("default", String("DE3C6578-C046-4911-838D-7C95BCD9231F"));
		info->queryParams["pimpersonid"].required = false;
	}

	// 4 定义接口端点
	ENDPOINT(API_M_GET, "/archives/select", queryArchives, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ArchivesQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private:
	// 5 定义接口的执行函数
	ArchivesPageJsonVO::Wrapper execQueryTest(const ArchivesQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) // 0
#endif // !_ARCHIVESCONTROLLER_H_

