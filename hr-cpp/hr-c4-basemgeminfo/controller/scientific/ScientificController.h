#pragma once
#ifndef _SCIENTIFICCONTROLLER_H_
#define _SCIENTIFICCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/scientific/ScientificQuery.h"
#include "domain/vo/scientific/ScientificVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ScientificController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ScientificController);
public: // 定义接口
	//查看指定员工科研成果(指定科研成果详情)
	ENDPOINT_INFO(queryScientific) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("scientific.get.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(ScientificJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("PIMARMYCADRESID").description = ZH_WORDS_GETTER("scientific.PIMARMYCADRESID");
		info->queryParams["PIMARMYCADRESID"].addExample("default", String("QWER-ASFD"));
	}
	ENDPOINT(API_M_GET, "/scientific", queryScientific, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ScientificViewQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryScientific(query));
	}
	//修改指定科研成果(单条修改)
	ENDPOINT_INFO(modifyScientific) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("scientific.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_PUT, "/scientific", modifyScientific, BODY_DTO(ScientificDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyScientific(dto));
	}
	//导出指定员工科研成果(导出本页在前端完成)
	ENDPOINT_INFO(downloadScientific) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("scientific.download.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 添加其他查询参数
		info->queryParams.add<String>("PIMPERSONID").description = ZH_WORDS_GETTER("scientific.PIMPERSONID");
		info->queryParams["PIMPERSONID"].addExample("default", String("0000-QWDE"));
	}
	ENDPOINT(API_M_POST, "/scientific", downloadScientific, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, ScientificDownloadQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execDownloadScientific(query));
	}
private: // 定义接口执行函数
	ScientificJsonVO::Wrapper execQueryScientific(const ScientificViewQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execModifyScientific(const ScientificDTO::Wrapper& dto);
	StringJsonVO::Wrapper execDownloadScientific(const ScientificDownloadQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SCIENTIFICCONTROLLER_H_