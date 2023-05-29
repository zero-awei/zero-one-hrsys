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
#include "domain/query/projTag/ExportProjTagQuery.h"
#include "domain/query/projTag/PageProjTagQuery.h"

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
	bool insert(const ProjTagDO& iObj);
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
	/**
	 * 项目标签 - 修改项目标签DAO实现
	 * 功能：更新指定项目标签唯一标识更新项目标签数据
	 * 负责人：Andrew
	 */
	bool updateProjTag(const ProjTagDO& data);

	/**
	 * 项目标签 - 导入项目标签DAO实现
	 * 功能：将文件中的数据导入到数据库中
	 * 负责人：远翔
	 */
	std::list<std::string> insertMultiTag(const std::list<ProjTagDO>& data);
	/**
	 * 项目标签 - 导出项目标签DAO实现
	 * 功能：查询最多5000条数据到DO并返回
	 * 负责人：Andrew
	 */
	std::list<ProjTagDO> exportProjTag(const ExportProjTagQuery::Wrapper& query);
	/**
	 * 项目标签 - 分页查询项目标签列表DAO实现
	 * 功能：数据条数计数
	 * 负责人：咫尺之书
	 */
	uint64_t count(const PageProjTagQuery::Wrapper& query);
	/**
	 * 项目标签 - 分页查询项目标签列表DAO实现
	 * 功能：查询项目标签列表，进行数据分页
	 * 负责人：咫尺之书
	 */
	std::list<ProjTagDO> selectProjTag(const PageProjTagQuery::Wrapper& query);
	/**
	 * 获取项目标签表头
	 * 负责人：Andrew
	 */
	vector<std::string> getHead();
};

#endif // !_PROJTAGDAO_H_