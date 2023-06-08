#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 19:59:13

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
#ifndef _SCIRESULTDAO_H_
#define _SCIRESULTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/sciresult/SciResultDO.h"
#include "../../domain/query/sciresult/SciResultQuery.h"

class SciResultDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const SciResultQuery::Wrapper& query);
	// 分页查询数据
	list<SciResultDO> selectWithPage(const SciResultQuery::Wrapper& query);
	// 插入数据
	int insert(const SciResultDO& iObj);
	// 通过ID删除数据
	int deleteById(std::string pimpersonid, std::string pimsciresultid);
};

#endif // !_SCIRESULTDAO_H_

