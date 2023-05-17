#pragma once
#ifndef  _MYCONTROLLER_H_
#define  _MYCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/sample/MyDto.h"

// 0 定义API控制器使用宏  (api控制器是处理传入请求，返回响应的)

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */

class TestController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	/*
	2 定义控制器访问入口
	2.1 API控制器可以根据传入请求的URL和HTTP方法分类，然后将请求路由到相应的方法和服务中进行处理
	*/
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
		/*
		接受表单参数的时候需要用宏   QUERIES(QueryParams, qp1)
		定义了默认授权参数需要在路径(/query)后面加上 API_HANDLER_AUTH_PARAME
		API_M_GET：是请求方式，表示get
		"/query",：url的路径
		queryTest：接口名字
		QUERIES(QueryParams, qp1)：表示请求是表单数据，请求的参数都放到qp1中
		*/
	ENDPOINT(API_M_GET, "/query", queryTest, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qp1))
	{
		/* 
		解析查询参数(解析为领域模型对象) 也就是query与dto
		首先调用API_HANDLER_QUERY_PARAM宏解析请求中的查询参数(也就是pq1)，
		将其解析（转换）为PageQuery类的对象，并以名称query保存在内存中。
		*/
		API_HANDLER_QUERY_PARAM(query, PageQuery, qp1);
		/*
		响应结果
		然后调用execQueryTest()方法执行查询操作，
		并使用API_HANDLER_RESP_VO宏将结果封装到StringJsonVO类对象中进行响应。
		*/
		API_HANDLER_RESP_VO(execQueryTest(query));
	}


	//// 3.1 定义查询接口描述
	//ENDPOINT_INFO(queryTest1)
	//{
	//	// 定义接口标题 固定写法
	//	info->summary = "query test1";
	//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数类型
	//	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//	// 定义分页参数描述
	//	API_DEF_ADD_PAGE_PARAMS();
	//}

	//// 3.2 定义查询接口处理
	//	//接受表单参数的时候需要用宏   QUERIES(QueryParams, qp1)
	//	//定义了默认授权参数需要在路径(/query)后面加上 API_HANDLER_AUTH_PARAME
	//ENDPOINT(API_M_GET, "/query1", queryTest1, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, qp2))
	//{
	//	// 解析查询参数(解析为领域模型对象) 也就是query与dto
	//	API_HANDLER_QUERY_PARAM(query1, PageQuery, qp2);
	//	// 响应结果
	//	API_HANDLER_RESP_VO(execQueryTest(query1));
	//}

	// 
		// 3.1 定义新增接口描述
	//ENDPOINT_INFO(addSample) {
	//	// 定义接口标题
	//	info->summary = ZH_WORDS_GETTER("sample.post.summary");
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	//}
	//// 3.2 定义新增接口处理
	//ENDPOINT(API_M_POST, "/sample", addSample, BODY_DTO(SampleDTO::Wrapper, dto)) {
	//	// 响应结果
	//	API_HANDLER_RESP_VO(execAddSample(dto));
	//}


	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addTest) {
		// 定义接口标题
		info->summary = "add test";
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/add", addTest, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execAddSample1(dto));
	}


	// 3.1 定义修改接口描述
	ENDPOINT_INFO(changeTest) {
		// 定义接口标题
		info->summary = "change test";
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/change", changeTest, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifySample(dto));
	}

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeTest) {
		// 定义接口标题
		info->summary = "remove test";
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义删除接口处理
	ENDPOINT(API_M_DEL, "/remove", removeTest, BODY_DTO(ContractDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execRemoveSample(dto));
	}
private:
	//定义接口的执行函数
	StringJsonVO::Wrapper execQueryTest(const PageQuery::Wrapper& query);

	Uint64JsonVO::Wrapper execAddSample1(const ContractDTO::Wrapper& dto);

	Uint64JsonVO::Wrapper execModifySample(const ContractDTO::Wrapper& dto);
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execRemoveSample(const ContractDTO::Wrapper& dto);


};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen


#endif // ! _MYCONTROLLER_H_
