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
#include "domain/vo/org/OrgTreeVO.h"
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
	ENDPOINT_INFO(orgTreeQuery)
	{
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("org.field.summary");
		// 添加默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON(OrgTreeVO::Wrapper);
		// 定义其他表单参数描述
		// 查询Sector的parent是OrmOrg还是OrmOrgsector
	}
	// 定义查询部门信息接口端点处理
	ENDPOINT(API_M_GET, "/c3-employee-info/organization-department-tree-structure/orgtree-query", orgTreeQuery, API_HANDLER_AUTH_PARAME)
	{
		// 响应结果
		API_HANDLER_RESP_VO(execOrgTreeQuery(authObject));
		// API_HANDLER_RESP_VO(execOrgTreeQuery(nullptr));
	}

private: // 定义接口执行函数
	// 查询组织结构树
	OrgTreeVO::Wrapper execOrgTreeQuery(const std::shared_ptr<CustomerAuthorizeObject> &authObject);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGNAIZATION_DEPARTMENT_TREE_STRUCTURE_