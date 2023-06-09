#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/18 20:27:52

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
#ifndef _FAMILYSITUATIONSERVICE_H_
#define _FAMILYSITUATIONSERVICE_H_

#include "domain/dto/familysituation/FamilysituationDTO.h"
#include "domain/query/familysituation/FamilysituationQuery.h"
#include "domain/vo/familysituation/FamilysituationVO.h" 

class FamilysituationService
{
public:
	// 分页查询所有数据
	FamilysituationPageDTO::Wrapper listAll(const FamilysituationQuery::Wrapper& query);
	// 指定查询数据
	FamilysituationDTO::Wrapper getOne(const FamilysituationQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const FamilysituationDTO::Wrapper& dto, const std::string authId);
	// 修改数据
	bool updateData(const FamilysituationDTO::Wrapper& dto, const std::string authId);
	// 通过ID删除数据
	int removeData(const FamilyBatchDeleteDTO::Wrapper& dto);
};

#endif // !_FAMILYSITUATIONSERVICE__