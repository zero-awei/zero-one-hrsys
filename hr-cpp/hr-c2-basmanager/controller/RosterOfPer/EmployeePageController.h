/*
（人员花名册-人员花名册-分页查询员工列表）--洛洛
*/
#ifndef _EMPLOYEEPAGECONTROLLER_H_
#define _EMPLOYEEPAGECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/RosterOfPer/EmployeePageDTO.h"
#include "domain/query/RosterOfPer/EmployeePageQuery.h"
#include "domain/vo/RosterOfPer/EmployeePageVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
#include OATPP_CODEGEN_BEGIN(ApiController)

class EmployeePageController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(EmployeePageController);
public: // 定义接口
	    // 定义查询接口描述
	ENDPOINT_INFO(queryEmployeePage) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeePageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("idAndName").description = ZH_WORDS_GETTER("employee.field.idAndName");
		info->queryParams["idAndName"].addExample("default", String("2032****"));
		info->queryParams["idAndName"].required = false;
		
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/query-employeePage", queryEmployeePage, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, EmployeePageQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryEmployeePage(userQuery, authObject->getPayload()));
	}
private: // 定义接口执行函数
	// 演示分页查询数据
	EmployeePageJsonVO::Wrapper execQueryEmployeePage(const EmployeePageQuery::Wrapper& query, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EMPLOYEEPAGECONTROLLER_H_
