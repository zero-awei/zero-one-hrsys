#pragma once

#ifndef _PAPERINFO_CONTROLLER_H_
#define _PAPERINFO_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/dto/paperinfo/PaperDTO.h"
#include "domain/vo/paperinfo/PaperVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

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
		API_DEF_ADD_RSP_JSON_WRAPPER(PaperJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	//4 定义接口端点
	ENDPOINT(API_M_GET, "/test", queryPaperinfo, QUERIES(QueryParams, qps)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//响应结果
		API_HANDLER_RESP_VO(execQueryPaperinfo(query));
	}
private: // 定义接口执行函数
	//5 定义接口执行函数
	StringJsonVO::Wrapper execQueryPaperinfo(const PageQuery::Wrapper& query);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) // 0
#endif // _SAMPLE_CONTROLLER_