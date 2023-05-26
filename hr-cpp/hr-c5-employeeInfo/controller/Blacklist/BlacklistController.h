#pragma once

#ifndef _BLACKLIST_CONTROLLER_H_
#define _BLACKLIST_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/Blacklist/BlacklistQuery.h"
#include "domain/vo/Blacklist/BlacklistVO.h"
#include "domain/dto/Blacklist/BlacklistDTO.h"

using namespace oatpp;

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class BlacklistController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(BlacklistController);
public: // 定义接口
	// 3 定义接口描述
	ENDPOINT_INFO(queryBlacklist) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("blacklist.get.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(BlacklistPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 4 定义接口端点
	ENDPOINT(API_M_GET, "/blacklist/query-blacklist", queryBlacklist, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, BlacklistQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryBlacklist(query));
	}
private: // 定义接口执行函数
	// 5 定义接口的执行函数
	BlacklistPageJsonVO::Wrapper execQueryBlacklist(const BlacklistQuery::Wrapper& query);
};



#include OATPP_CODEGEN_END(ApiController) // 0

#endif 