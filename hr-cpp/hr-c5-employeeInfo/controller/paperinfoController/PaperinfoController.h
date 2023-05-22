#pragma once

#ifndef _PAPERINFO_CONTROLLER_
#define _PAPERINFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/vo/paperinfo/PaperVO.h"

/*
	论文信息控制器
*/


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

class PaperinfoController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PaperinfoController);
public: // 定义接口
	//3 定义接口描述
	ENDPOINT_INFO(queryPaperinfo) {
		//定义接口标题
		info->summary = ZH_WORDS_GETTER("paperinfo.get.summary");
		//定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(PaperPageJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 其他表单参数
		info->queryParams.add<String>("pimpersonid").description = ZH_WORDS_GETTER("paperinfo.field.pimpersonid");
		info->queryParams["pimpersonid"].addExample("default", String("10001"));
		info->queryParams["pimpersonid"].required = true;
	}
	//4 定义接口端点
	ENDPOINT(API_M_GET, "/employee-info/query-by-pimpersonid", queryPaperinfo, QUERIES(QueryParams, qps)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//响应结果
		API_HANDLER_RESP_VO(execQueryPaperinfo(query));
	}

	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifySample) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("paperinfo.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/employee-info/modify-paperinfo", modifySample, BODY_DTO(PaperDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyPaperinfo(dto));
	}

private: // 定义接口执行函数
	//5 定义接口执行函数
	PaperPageJsonVO::Wrapper execQueryPaperinfo(const PageQuery::Wrapper& query);

	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyPaperinfo(const PaperDTO::Wrapper& dto);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) // 0
#endif 