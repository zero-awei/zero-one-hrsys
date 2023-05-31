#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/20 14:36:04

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
#ifndef _LEGALENTITYMAISERVICE_H_
#define _LEGALENTITYMAISERVICE_H_
#include <list>
#include "domain/dto/LegalEntitySet/LegalEntitySetQueryDTO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"

/* 法人主体设置服务实现--（组织管理-数据设置-法人主体设置）--TripleGold */
class LegalEntitySetService
{
public:
	// 分页查询所有数据
	LegalEntitySetPageDTO::Wrapper listAll(const LegalEntitySetQuery::Wrapper& query);
};

#endif // !_LEGALENTITYMAISERVICE_H_