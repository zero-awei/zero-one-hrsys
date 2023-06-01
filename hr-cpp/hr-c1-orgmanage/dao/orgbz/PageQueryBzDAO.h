#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/31 1:04:41

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
#ifndef _PAGEQUERYBZDAO_H_
#define _PAGEQUERYBZDAO_H_
#include "BaseDAO.h"
#include "domain/do/orgbz/PageQueryBzDO.h"
#include "domain/query/orgbz/PageBzQuery.h"

class PageQueryBzDAO : public BaseDAO
{
public:
	uint64_t count(const PageQueryBzQuery::Wrapper& query);
	std::list<PageQueryBzDO> selectPageQueryBz(const PageQueryBzQuery::Wrapper & query);
};

#endif // !_PAGEQUERYBZDAO_H_