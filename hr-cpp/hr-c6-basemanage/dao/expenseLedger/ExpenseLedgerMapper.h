/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/27 9:28:14

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
#ifndef _EXPENSELEDGER_MAPPER_
#define _EXPENSELEDGER_MAPPER_
#include "Mapper.h"
#include "domain/do/expenseLedger/ExpenseLedgerDO.h"

class ExpenseLedgerMapper : public Mapper<ExpenseLedgerDO>
{
public:
	ExpenseLedgerDO mapper(ResultSet* resultSet) const override
	{
		ExpenseLedgerDO data;
		data.setName(resultSet->getString(1));
		data.setId(resultSet->getString(2));
		data.setUpdateman(resultSet->getString(3));
		data.setCreatedate(resultSet->getString(4));
		data.setCreateman(resultSet->getString(5));
		data.setUpdatedate(resultSet->getString(6));
		data.setFylb(resultSet->getString(7));
		data.setFyje(resultSet->getDouble(8));
		data.setFfrs(resultSet->getInt(9));
		data.setFfsj(resultSet->getString(10));
		data.setFybz(resultSet->getString(11));
		data.setBz(resultSet->getString(12));
		data.setOrmorgid(resultSet->getString(13));
		return data;
	}
};
#endif