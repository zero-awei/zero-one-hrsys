#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:06:40

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
#ifndef _PROJTAGDAO_H_
#define _PROJTAGDAO_H_
#include "BaseDAO.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "domain/do/projTag/OrgListDO.h"
#include "domain/query/projTag/OrgListQuery.h"

/**
 * 项目标签DAO实现
 */
class ProjTagDAO : public BaseDAO
{
public:
	/**
	 * 项目标签 - 新增项目标签DAO实现
	 * 负责人：远翔
	 */
	uint64_t insert(const ProjTagDO& iObj);
	/**
	 * 项目标签 - 分页查询组织列表DAO实现
	 * 功能：查询组织列表，进行数据分页
	 * 负责人：Andrew
	 */
	std::list<OrgListDO> selectOrgList(const OrgListQuery::Wrapper& query);
	/**
	 * 项目标签 - 分页查询组织列表DAO实现
	 * 功能：数据条数计数
	 * 负责人：Andrew
	 */
	uint64_t count(const OrgListQuery::Wrapper& query);
};

#endif // !_PROJTAGDAO_H_