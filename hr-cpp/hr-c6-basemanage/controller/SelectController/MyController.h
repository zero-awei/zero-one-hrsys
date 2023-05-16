#pragma once
#ifndef  _MYCONTROLLER_H_
#define  _MYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"

// 0 定义API控制器使用宏  (api控制器是处理传入请求，返回响应的)

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */

class TestController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	// 2.1 API控制器可以根据传入请求的URL和HTTP方法分类，然后将请求路由到相应的方法和服务中进行处理
	API_ACCESS_DECLARE(TestController);
	// 3 定义接口
public:

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryTest) 
	{
		// 定义接口标题 固定写法
		info->summary = "query test";
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}

	// 3.2 定义查询接口处理
		//接受表单参数的时候需要用宏   QUERIES(QueryParams, qp1)
		//定义了默认授权参数需要在路径(/query)后面加上 API_HANDLER_AUTH_PARAME
	ENDPOINT(API_M_GET, "/query", queryTest, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qp1))
	{
		// 解析查询参数(解析为领域模型对象) 也就是query与dto
		API_HANDLER_QUERY_PARAM(query, PageQuery, qp1);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryTest(query));
	}

	
private:
	//定义接口的执行函数
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif // ! _MYCONTROLLER_H_
