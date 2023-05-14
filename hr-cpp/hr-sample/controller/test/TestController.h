#pragma once

#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"

/*
	测试控制器
*/


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) // 0

class TestController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(TestController);
public: // 定义接口
	//3 定义接口描述
	ENDPOINT_INFO(queryTest) {
		//定义接口标题
		info->summary = "test query";
		//定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	//4 定义接口端点
	ENDPOINT(API_M_GET, "/test", queryTest, QUERIES(QueryParams, qps)) {
		//解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, PageQuery, qps);
		//响应结果
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private: // 定义接口执行函数
	//5 定义接口执行函数
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);


};




// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) // 0
#endif // _SAMPLE_CONTROLLER_