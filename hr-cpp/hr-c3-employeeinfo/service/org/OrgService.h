#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2022/10/25 11:08:56

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
#ifndef _ORG_SERVICE_
#define _ORG_SERVICE_
#include <list>
// #include "domain/vo/org/"
#include "domain/query/orgquery/RootOrgQuery.h"
#include "domain/query/orgquery/SectorQuery.h"
#include "domain/query/orgquery/ValidOrgQuery.h"
#include "domain/dto/org/OrgDTO.h"
#include "domain/dto/org/OrgSectorDTO.h"
#include "dao/org/OrgDAO.h"
#include "dao/org/OrgSectorDAO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class OrgService
{
public:
	// 查询根组织
	OrgPageDTO::Wrapper getRootOrg(const RootOrgQuery::Wrapper &query, const string &userID);

	// 查询子组织
	OrgPageDTO::Wrapper getValidOrg(const ValidOrgQuery::Wrapper &query);

	// 查询子部门
	OrgSectorPageDTO::Wrapper getSector(const SectorQuery::Wrapper &query);
};

#endif // !_ORG_SERVICE_

