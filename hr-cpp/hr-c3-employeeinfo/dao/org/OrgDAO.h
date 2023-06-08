#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2022/10/25 14:23:49

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
#ifndef _Org_DAO_
#define _Org_DAO_
#include "BaseDAO.h"
#include "../../domain/do/org/OrgTreeDO.h"
#include "../../dao/org/OrgTreeMapper.h"

/**
 * 示例表数据库操作实现
 */
class OrgDAO : public BaseDAO
{
public:
    // 查询根组织数据
    list<OrgTreeDO> selectRootOrg(const string &userId);
    // 查询某个父组织下面的组织
    list<OrgTreeDO> selectValidOrg(const string& parentId); 

    list<OrgTreeDO> selectOrgSector(const string& parentId); 
};
#endif // !_Org_DAO_