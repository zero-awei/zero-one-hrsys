/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/19 23:25:14

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
#include "stdafx.h"
#include "ExpenseLedgerController.h"
#include "service/expenseLedger/ExpenseLedgerService.h"


ExpenseLedgerPageJsonVO::Wrapper ExpenseLedgerMController::execQueryExpenseLedger(const ExpenseLedgerPageQuery::Wrapper& query)
{
	ExpenseLedgerService service;
	auto result = service.ListAll(query);

	auto jvo = ExpenseLedgerPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper ExpenseLedgerMController::execAddExpenseLedger(const ExpenseLedgerDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();
	if (!dto->pimexpaccountname || !dto->pimexpaccountid || !dto->fyje || !dto->ffrs || !dto->ffybz) 
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	if (dto->pimexpaccountname->empty() || dto->ffybz->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	ExpenseLedgerService service;
	if (service.saveData(dto)) {
		jvo->success(dto->pimexpaccountname);
	}
	else
	{
		jvo->fail(dto->pimexpaccountname);
	}
	return jvo;
}



StringJsonVO::Wrapper ExpenseLedgerMController::execDeleteExpenseLedger()
{
	return StringJsonVO::Wrapper();
}


