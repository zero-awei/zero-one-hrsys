#pragma once
/*
（人员花名册-人员花名册-导出员工（导出本页在前端完成））--luoluo
*/
#ifndef _EXPORTEMPLOYEE_CONTROLLER_
#define _EXPORTEMPLOYEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

#include "domain/query/RosterOfPer/ExportEmployeeQuery.h"
#include "domain/dto/RosterOfPer/ExportEmployeeDTO.h"
#include "domain/vo/RosterOfPer/ExportEmployeeJsonVO.h"

#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ExportEmployeeController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExportEmployeeController);
	// 定义接口
public:
	// 定义查询接口描述
	ENDPOINT_INFO(exportEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("employee.export.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExportEmployeeJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("sample.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;
		info->queryParams.add<String>("sex").description = ZH_WORDS_GETTER("sample.field.sex");
		info->queryParams["sex"].addExample("default", String("N"));
		info->queryParams["sex"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/export-employee", exportEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, ExportEmployeeQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportEmployee(userQuery, authObject->getPayload()));
	}

private:
	// 演示分页查询数据
	ExportEmployeeJsonVO::Wrapper execExportEmployee(const ExportEmployeeQuery::Wrapper& query, const PayloadDTO& payload);

};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPORTEMPLOYEE_CONTROLLER_