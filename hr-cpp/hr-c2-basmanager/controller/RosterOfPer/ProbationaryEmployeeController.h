#pragma once
/**
 *  基础管理 —— 人员花名册 —— 试用员工 —— 楚孟献
 */

#ifndef _PROBATIONARY_EMPLOYEE_CONTROLLER_
#define _PROBATIONARY_EMPLOYEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/RosterOfPer/ProbationaryEmployeeQuery.h"
#include "domain/dto/RosterOfPer/ProbationaryEmployeeDTO.h"
#include "domain/vo/RosterOfPer/ProbationaryEmployeeVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ProbationaryEmployeeController : public oatpp::web::server::api::ApiController // 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ProbationaryEmployeeController);
	// 定义接口
public:
	// 定义查询接口描述 询问所有试用员工数据
	ENDPOINT_INFO(queryProbationaryEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("probationaryemployee.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProbationaryEmployeePageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("id_or_name").description = ZH_WORDS_GETTER("formeremployees.field.id_or_name");
		info->queryParams["id_or_name"].addExample("default", String("1"));
		info->queryParams["id_or_name"].required = false;

		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["id"].addExample("default", String(""));
		info->queryParams["id"].required = false;

		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("formeremployees.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;

		info->queryParams.add<String>("zjhm").description = ZH_WORDS_GETTER("probationaryemployee.field.zjhm");
		info->queryParams["zjhm"].addExample("default", String(""));
		info->queryParams["zjhm"].required = false;

		info->queryParams.add<String>("organization").description = ZH_WORDS_GETTER("probationaryemployee.field.organization");
		info->queryParams["organization"].addExample("default", String(""));
		info->queryParams["organization"].required = false;

		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;

		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("probationaryemployee.field.ygzt");
		info->queryParams["ygzt"].addExample("default", String(""));
		info->queryParams["ygzt"].required = false;

		info->queryParams.add<String>("zgzt").description = ZH_WORDS_GETTER("probationaryemployee.field.zgzt");
		info->queryParams["zgzt"].addExample("default", String(""));
		info->queryParams["zgzt"].required = false;

	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/query-all-ProbationaryEmployee", queryProbationaryEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(Query, ProbationaryEmployeeQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryProbationaryEmployee(Query, authObject->getPayload()));
	}

	// 定义导出接口描述
	ENDPOINT_INFO(exportProbationaryEmployee) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("probationaryemployee.get.out");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他表单参数描述
		info->queryParams.add<String>("id_or_name").description = ZH_WORDS_GETTER("formeremployees.field.id_or_name");
		info->queryParams["id_or_name"].addExample("default", String("1"));
		info->queryParams["id_or_name"].required = false;

		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sample.field.id");
		info->queryParams["id"].addExample("default", String(""));
		info->queryParams["id"].required = false;

		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("formeremployees.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		info->queryParams["name"].required = false;

		info->queryParams.add<String>("zjhm").description = ZH_WORDS_GETTER("probationaryemployee.field.zjhm");
		info->queryParams["zjhm"].addExample("default", String(""));
		info->queryParams["zjhm"].required = false;

		info->queryParams.add<String>("organization").description = ZH_WORDS_GETTER("probationaryemployee.field.organization");
		info->queryParams["organization"].addExample("default", String(""));
		info->queryParams["organization"].required = false;

		info->queryParams.add<String>("bm").description = ZH_WORDS_GETTER("probationaryemployee.field.bm");
		info->queryParams["bm"].addExample("default", String(""));
		info->queryParams["bm"].required = false;

		info->queryParams.add<String>("ygzt").description = ZH_WORDS_GETTER("probationaryemployee.field.ygzt");
		info->queryParams["ygzt"].addExample("default", String(""));
		info->queryParams["ygzt"].required = false;

		info->queryParams.add<String>("zgzt").description = ZH_WORDS_GETTER("probationaryemployee.field.zgzt");
		info->queryParams["zgzt"].addExample("default", String(""));
		info->queryParams["zgzt"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/get-ProbationaryEmployee", exportProbationaryEmployee, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(Query, ProbationaryEmployeeQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execExportProbationaryEmployee(Query, authObject->getPayload()));
	}
private:
	// 分页查询试用员工数据
	ProbationaryEmployeePageJsonVO::Wrapper execQueryProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload);
	// 返回试用员工Excel表格
	StringJsonVO::Wrapper execExportProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload);
};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PROBATIONARY_EMPLOYEE_CONTROLLER_