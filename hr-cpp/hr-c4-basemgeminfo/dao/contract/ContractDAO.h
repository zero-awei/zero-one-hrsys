#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 14:01:37

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
#ifndef _CONTRACTDAO_H_
#define _CONTRACTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/contract/ContractDO.h"
#include "../../domain/query/contract/ContractQuery.h"

class ContractDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ContractQuery::Wrapper& query);
	// 分页查询数据
	list<ContractDO> selectWithPage(const ContractQuery::Wrapper& query);
};

#endif // !_CONTRACTDAO_H_