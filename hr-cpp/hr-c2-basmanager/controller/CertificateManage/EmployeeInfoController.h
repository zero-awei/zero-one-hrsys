#pragma once
/**
* 证书管理人员信息查询，搜索框使用--(证书管理-分页查询员工信息)-weixiaoman
*/

#ifndef _EMPLOYEEINFO_CONTROLLER_
#define _EMPLOYEEINFO_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/CertificateManage/EmployeeInfoQuery.h"
#include "domain/dto/CertificateManage/EmployeeInfoDTO.h"
#include "domain/vo/CertificateManage/EmployeeInfoVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"

using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 人员信息查询功能控制器
 */
class EmployeeInfoController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(EmployeeInfoController);

	// 定义接口
public:
	// 定义查询接口描述
	ENDPOINT_INFO(queryEmpInfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("EmpInfo.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EmployeeInfoPageJsonVO);
		// 定义分页参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		info->queryParams.add<String>("name").description = ZH_WORDS_GETTER("EmpInfo.field.name");
		info->queryParams["name"].addExample("default", String("li ming"));
		//info->queryParams["name"].required = false;
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/bas/query-employeeinfo", queryEmpInfo, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, EmployeeInfoQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryEmpInfo(userQuery, authObject->getPayload()));
	}
private:
	// 人员信息分页查询数据
	EmployeeInfoPageJsonVO::Wrapper execQueryEmpInfo(const EmployeeInfoQuery::Wrapper& query, const PayloadDTO& payload);

};

// 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_EMPLOYEEINFO_CONTROLLER_