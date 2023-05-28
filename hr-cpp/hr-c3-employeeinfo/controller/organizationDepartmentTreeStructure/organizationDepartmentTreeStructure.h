#pragma once


#ifndef _ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_
#define _ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
//#include "domain/query/EmployeeInformationPageQuery/EmployeeInformationPageQuery.h"
//#include "domain/vo/EmployeeInformation/EmployeeInformationVO.h"
//#include "domain/dto/AddEmployeeAssignInfo/AddEmployeeAssignInfo.h"
//#include "domain/dto/EmployeeInformationPageQuery/EmployeeInformationPageQueryDTO.h"
#include "domain/vo/org/MemberVO.h"
#include "domain/query/orgquery/RootOrgQuery.h"
#include "domain/query/orgquery/ValidOrgQuery.h"
#include "domain/vo/org/OrgSectorVO.h"
#include "domain/query/orgquery/SectorQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/*
* 定义查询所有部门结构树信息接口端点处理
*/
class organizationDepartmentTreeStructure : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(organizationDepartmentTreeStructure);
public: // 定义接口

	//定义查询根组织信息接口端点描述
	ENDPOINT_INFO(rootOrgQuery) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("org.field.root");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(MemberJsonVO::Wrapper);
	
	}
	//定义查询根组织信息接口端点处理
	ENDPOINT(API_M_GET, "/organization-department-tree-structure/root-org-query", rootOrgQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(rootQuery,RootOrgQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execRootOrgQuery(rootQuery));
	}

	//定义查询有效组织信息接口端点描述
	ENDPOINT_INFO(validOrgQuery) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("org.field.validorg");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(MemberJsonVO::Wrapper);

	}
	//定义查询有效组织信息接口端点处理
	ENDPOINT(API_M_GET, "/organization-department-tree-structure/valid-org-query", validOrgQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(validOrg, ValidOrgQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execValidOrgQuery(validOrg));
	}

	//定义查询部门信息接口端点描述
	ENDPOINT_INFO(secotrOrgQuery) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("org.field.sector");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(OrgSectorVO::Wrapper);

	}
	//定义查询部门信息接口端点处理
	ENDPOINT(API_M_GET, "/organization-department-tree-structure/sector-org-query", secotrOrgQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(sectorOrg, SectorQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execSectorOrgQuery(sectorOrg));
	}


private: // 定义接口执行函数
	//查询根组织
	MemberJsonVO::Wrapper execRootOrgQuery(const RootOrgQuery::Wrapper& rootQuery);
	//查询有效组织
	MemberJsonVO::Wrapper execValidOrgQuery(const ValidOrgQuery::Wrapper& validOrg);
	//查询部门
	OrgSectorVO::Wrapper execSectorOrgQuery(const SectorQuery::Wrapper& sectorOrg);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_