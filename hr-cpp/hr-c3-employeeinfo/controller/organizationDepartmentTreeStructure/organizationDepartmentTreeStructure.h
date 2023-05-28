#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/24 15:14:27

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

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
#include "domain/vo/org/OrgVO.h"
#include "domain/query/orgquery/SectorQuery.h"
#include "service/org/OrgService.h"

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
		// 定义其他表单参数描述
        // 搜索匹配
		info->queryParams.add<String>("filter").description = ZH_WORDS_GETTER("rootorg.query.filter");
		info->queryParams["filter"].addExample("default", String("filter"));
		//排序方式
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("rootorg.query.sort");
		info->queryParams["sort"].addExample("default", String("sort"));
	
	}
	//定义查询根组织信息接口端点处理
	ENDPOINT(API_M_GET, "/organization-department-tree-structure/root-org-query", rootOrgQuery, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(rootQuery,RootOrgQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execRootOrgQuery(rootQuery, authObject));
	}

	//定义查询有效组织信息接口端点描述
	ENDPOINT_INFO(validOrgQuery) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("org.field.validorg");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(MemberJsonVO::Wrapper);
		// 定义其他表单参数描述
		// 搜索匹配
		info->queryParams.add<String>("fillter").description = ZH_WORDS_GETTER("validorg.query.filter");
		info->queryParams["fillter"].addExample("default", String("fillter"));
		//父组织id
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("validorg.query.porgid");
		info->queryParams["id"].addExample("default", String("10001"));
		//排序方式
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("validorg.query.sort");
		info->queryParams["sort"].addExample("default", String("sort"));
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
		// 定义其他表单参数描述
		// 查询Sector的parent是OrmOrg还是OrmOrgsector
		info->queryParams.add<String>("parentdename").description = ZH_WORDS_GETTER("sector.query.sort");
		info->queryParams["parentdename"].addExample("default", String("OrmOrg"));
		//上级部门id
		info->queryParams.add<String>("id").description = ZH_WORDS_GETTER("sector.query.parentkey");
		info->queryParams["id"].addExample("default", String("10001"));
		//排序方式
		info->queryParams.add<String>("sort").description = ZH_WORDS_GETTER("sector.query.sort");
		info->queryParams["sort"].addExample("default", String("sort"));
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
	OrgJsonVO::Wrapper execRootOrgQuery(const RootOrgQuery::Wrapper& rootQuery, const std::shared_ptr<CustomerAuthorizeObject> &authObject);
	//查询有效组织
	OrgJsonVO::Wrapper execValidOrgQuery(const ValidOrgQuery::Wrapper& validOrg);
	//查询部门
	OrgSectorVO::Wrapper execSectorOrgQuery(const SectorQuery::Wrapper& sectorOrg);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_