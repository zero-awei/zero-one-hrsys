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
#include "SimpleDateTimeFormat.h"
#include "SnowFlake.h"

ExpenseLedgerPageJsonVO::Wrapper ExpenseLedgerMController::execQueryExpenseLedger(const ExpenseLedgerPageQuery::Wrapper& query)
{
	auto jvo = ExpenseLedgerPageJsonVO::createShared();
	ExpenseLedgerService service;
	auto result = service.ListAll(query);
	if (result->rows->empty())
	{
		jvo->fail(result);
	} 
	else
	{
		jvo->success(result);
	}
	return jvo;}
/**
 * Returns: String StringJsonVO.data 插入费用台账的标识
 */
StringJsonVO::Wrapper ExpenseLedgerMController::execAddExpenseLedger(const ExpenseLedgerDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if ( !dto->pimexpaccountid || dto->fyje<=0 || dto->ffrs<=0 ) 
	{
		jvo->init("0", RS_PARAMS_INVALID);
		//jvo->init(String(-1), RS_SERVER_BUSY);
	}
	else {
		// 时间类设置记录创建和更新时间
		SimpleDateTimeFormat datesevice;
		dto->createdate = datesevice.format();
		dto->updatedate = datesevice.format();
		dto->createman = payload.getUsername();
		dto->updateman = payload.getUsername();
		// 
		SnowFlake uidservice(1,6);
		dto->pimexpaccountid = to_string(uidservice.nextId());
		ExpenseLedgerService service;
		if (service.saveData(dto))
		{
			jvo->success(dto->pimexpaccountname);
		}
		else {
			jvo->fail(dto->pimexpaccountname);
		}
	}
	return jvo;
}

/**
 * Returns: Uint64 Uint64JsonVO.data 受影响的行数
 */
Uint64JsonVO::Wrapper ExpenseLedgerMController::execDeleteExpenseLedger(const ExpenseLedgerDelQuery::Wrapper& query)
{
	auto jvo = Uint64JsonVO::createShared();
	int successTime = 0;
	ExpenseLedgerService service;
	for (std::size_t i=0;i < query->IDlist->size();i++)
	{
		successTime += service.removeData(query->IDlist[i]);
	}
	if (successTime>0)
	{
		jvo->success(successTime);
	} 
	else
	{
		jvo->init(uint64_t(0), RS_PARAMS_INVALID);
	}
	return jvo;
}




