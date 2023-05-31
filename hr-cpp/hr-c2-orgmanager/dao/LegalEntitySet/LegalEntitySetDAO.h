#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/25 10:29:23

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
#ifndef _LEGALENTITYSETDAO_H_
#define _LEGALENTITYSETDAO_H_
#include "BaseDAO.h"
#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/do/LegalEntityMai/ormsignorgDO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"
#include "domain/do/LegalEntitySet/QueryLegalEntitySetDO.h"

/* 法人主体设置DAO层设计--（组织管理-数据设置-法人主体设置）--TripleGold */
class LegalEntitySetDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const LegalEntitySetQuery::Wrapper& query);
	// 分页查询数据
	list<QueryLegalEntitySetDO> selectWithPage(const LegalEntitySetQuery::Wrapper& query);
};

#endif // !_LEGALENTITYSETDAO_H_