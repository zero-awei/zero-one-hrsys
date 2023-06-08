/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/27 0:16:41

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
#ifndef _EXPENSELEDGER_DAO_
#define _EXPENSELEDGER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/expenseLedger/ExpenseLedgerDO.h"
#include "../../domain/query/ExpenseLedger/ExpenseLedgerQuery.h"
#include "../../domain/dto/ExpenseLedger/ExpenseLedgerDTO.h"

class ExpenseLedgerDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ExpenseLedgerPageQuery::Wrapper& query);
	// ����ҳ�����󷵻�DO
	std::list<ExpenseLedgerDO> selectByPageQuery(const ExpenseLedgerPageQuery::Wrapper& query);

	// �����������ݣ���ѯ�������ݣ�
	std::list<ExpenseLedgerDO> selectAll(const ExpenseLedgerDTO::Wrapper& query);

	// �޸�����
	int update(const ExpenseLedgerDO& uObj);

	uint64_t insert(const ExpenseLedgerDO& ido);
	// ɾ������
	uint64_t deleteById(const ExpenseLedgerDO& obj);

	vector<string> getHead(const ExpenseLedgerDTO::Wrapper& query);
};
#endif