#pragma once

//Author: Diaukray

#ifndef _TRAININGRECORDCONTROLLER_H_
#define _TRAININGRECORDCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TrainingRecordController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(TrainingRecordController);
public: // 定义接口
	// 定义接口描述
	ENDPOINT_INFO(queryTest) {
		// 定义接口标题
		info->summary = "This is TrainingRecord PageQuery";
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	
	ENDPOINT(API_M_GET, "/trianingrecord", queryTest, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//响应结果
		API_HANDLER_RESP_VO(execQueryTest(query));
	}


private: // 定义接口执行函数
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif