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
#include OATPP_CODEGEN_BEGIN(ApiController) 

class PaperinfoController : public oatpp::web::server::api::ApiController
{
	//  定义控制器访问入口
	API_ACCESS_DECLARE(PaperinfoController);
public: // 定义接口
	// 定义分页查询指定员工论文信息接口描述
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
	// 定义接口端点处理
	ENDPOINT(API_M_GET, "/employee-info/query-paperinfo-by-pimpersonid", queryPaperinfo, QUERIES(QueryParams, qps)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, PaperQuery, qps);
		//响应结果
		API_HANDLER_RESP_VO(execQueryPaperinfo(query));
	}

	//  定义修改接口描述
	ENDPOINT_INFO(modifyPaperinfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("paperinfo.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//  定义修改接口处理
	ENDPOINT(API_M_PUT, "/employee-info/modify-paperinfo", modifyPaperinfo, BODY_DTO(PaperDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyPaperinfo(dto));
	}

	//  定义新增接口描述
	ENDPOINT_INFO(addPaperinfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("paperinfo.post.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	//  定义新增接口处理
	ENDPOINT(API_M_POST, "/employee-info/add-paperinfo", addPaperinfo, BODY_DTO(PaperDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddPaperinfo(dto));
	}

	//  定义删除接口描述
	ENDPOINT_INFO(removePimpaper) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("paperinfo.delete.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	//  定义删除接口处理
	ENDPOINT(API_M_DEL, "/employee-info/remove-paperinfo", removePimpaper, BODY_DTO(PaperDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemovePaperinfo(dto));
	}

private: // 定义接口执行函数
	// 分页查询论文信息
	PaperPageJsonVO::Wrapper execQueryPaperinfo(const PaperQuery::Wrapper& query);

	// 修改论文信息
	Uint64JsonVO::Wrapper execModifyPaperinfo(const PaperDTO::Wrapper& dto);

	// 添加论文信息
	Uint64JsonVO::Wrapper execAddPaperinfo(const PaperDTO::Wrapper& dto);

	// 删除论文信息
	Uint64JsonVO::Wrapper execRemovePaperinfo(const PaperDTO::Wrapper& dto);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) // 0
#endif 