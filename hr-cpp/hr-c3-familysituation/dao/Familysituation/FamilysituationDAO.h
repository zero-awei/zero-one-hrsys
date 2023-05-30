#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/29 20:15:29

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
#ifndef _FAMILYSITUATIONDAO_H_
#define _FAMILYSITUATIONDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/Familysituation/FamilysituationDO.h"
#include "../../domain/query/familysituation/FamilysituationQuery.h"

class FamilysituationDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const FamilysituationQuery::Wrapper& query);
	// 分页查询数据
	list<FamilysituationDO> selectWithPage(const FamilysituationQuery::Wrapper& query);
	// 指定查询数据
	list<FamilysituationDO> selectWithOne(const FamilysituationQuery::Wrapper& query);
	// 新增数据
	uint64_t insert(const FamilysituationDO& iObj);
	// 修改数据
	int update(const FamilysituationDO& uObj);
	// 删除数据
	int deleteById(FamilysituationDO& dObj);
};

#endif // !_FAMILYSITUATIONDAO_H_