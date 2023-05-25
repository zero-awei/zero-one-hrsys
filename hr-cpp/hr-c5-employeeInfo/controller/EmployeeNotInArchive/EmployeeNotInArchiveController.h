#pragma once
#ifndef _EMPLOYEE_NOT_IN_AECHIVE_CONTROLLER_
#define _EMPLOYEE_NOT_IN_AECHIVE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/EmployeeNotInArchive/EmployeeNotInArchiveVo.h"
#include "domain/query/EmployeeNotInArchive/EmployeeNotInArchiveQuery.h"
#include "domain/dto/EmployeeNotInArchive/EmployeeNotInArchiveDto.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * 测试控制器
 */
class EmployeeNotInArchiveController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(EmployeeNotInArchiveController);
public: // 定义接口
	// 3 定义接口描述
	ENDPOINT_INFO(EmployeeNotInArchive) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("EmployeeNotInArchive.get.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeeNotInArchivePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//员工姓名
		info->queryParams.add<String>("PimPersonName").description = ZH_WORDS_GETTER("EmployeeNotInArchive.field.PimPersonName");
		info->queryParams["PimPersonName"].addExample("default", String("Name"));
	}
	// 4 定义接口端点
	ENDPOINT(API_M_GET, "/employeenotInarchive", EmployeeNotInArchive, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, EmployeeNotInArchiveQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryTest(query));
	}
private: // 定义接口执行函数
	// 5 定义接口的执行函数
	EmployeeNotInArchivePageJsonVO::Wrapper execQueryTest(const EmployeeNotInArchiveQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_ARCHIVSE_CONTEOLLER_