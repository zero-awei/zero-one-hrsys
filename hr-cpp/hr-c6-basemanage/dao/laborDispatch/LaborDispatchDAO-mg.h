/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/20 10:46:18

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
#pragma once
#ifndef _LD_M_DAO_
#define _LD_M_DAO_
#include "BaseDAO.h"
#include "../../domain/query/LaborDispatch/LaborDispatchQuery-mg.h"
#include "../../domain/do/laborDispatch/LaborDispatchDO.h"

class LaborDispatchMDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const LaborDispatchMQuery::Wrapper& query);
	// 根据公司名称查询数据
	std::list<LaborDispatchDO> selectByCorporateID(const LaborDispatchMQuery::Wrapper& query);

	int update(const LaborDispatchDO& uDo);
protected:
private:
};

#endif