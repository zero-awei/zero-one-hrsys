#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 17:01:55

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
#ifndef _PROJTAGSERVICE_H_
#define _PROJTAGSERVICE_H_
#include "domain/dto/projTag/ProjTagDTO.h"
#include "domain/dto/projTag/OrgListDTO.h"
#include "domain/query/projTag/OrgListQuery.h"
#include "domain/query/projTag/PageProjTagQuery.h"
#include "domain/dto/projTag/ModifyTagDTO.h"

/**
 * 项目标签Service
 */
class ProjTagService
{
public:
	/**
	 * 新增项目标签
	 * 负责人：远翔
	 */
	uint64_t saveData(const ProjTagDTO::Wrapper& dto);
	/**
	 * 分页查询组织列表
	 * 负责人：Andrew
	 */
	OrgListPageDTO::Wrapper listOrgList(const OrgListQuery::Wrapper &query);
	/**
	 * 修改项目标签
	 * 负责人：Andrew
	 */
	bool updateProjTag(const ModifyTagDTO::Wrapper& dto, const PayloadDTO& payload);
	/**
	 * 分页查询项目标签
	 * 负责人：咫尺之书
	 */
	ProjTagPageDTO::Wrapper listProjTagList(const PageProjTagQuery::Wrapper& query);
};

#endif // !_PROJTAGSERVICE_H_
