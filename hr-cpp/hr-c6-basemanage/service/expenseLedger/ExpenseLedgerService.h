/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/26 23:55:14

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
#ifndef _EXPENSELEDGER_SERVICE_
#define _EXPENSELEDGER_SERVICE_
#include "domain/dto/ExpenseLedger/ExpenseLedgerDTO.h"
#include "domain/query/ExpenseLedger/ExpenseLedgerQuery.h"

class ExpenseLedgerService
{
public:
	// 分页查询数据
	ExpenseLedgerPageDTO::Wrapper ListAll(const ExpenseLedgerPageQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ExpenseLedgerDTO::Wrapper& dto);
	// 根据..删除数据
	bool removeData(String id);
protected:
private:
};

#endif