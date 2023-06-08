/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/27 0:02:50

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
#include "ExpenseLedgerService.h"
#include "domain/dto/ExpenseLedger/ExpenseLedgerDTO.h"
#include "dao/expenseLedger/ExpenseLedgerDAO.h"
#include "domain/do/expenseLedger/ExpenseLedgerDO.h"

ExpenseLedgerPageDTO::Wrapper ExpenseLedgerService::ListAll(const ExpenseLedgerPageQuery::Wrapper& query)
{
	//构建返回对象
	auto pages = ExpenseLedgerPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//查询数据总条数
	ExpenseLedgerDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//分页插叙数据
	pages->total = count;
	pages->calcPages();
	list<ExpenseLedgerDO> result = dao.selectByPageQuery(query);
	//将DO转换成DTO
	for (ExpenseLedgerDO sub : result)
	{
		auto dto = ExpenseLedgerDTO::createShared();
		dto->pimexpaccountname = sub.getName();
		dto->pimexpaccountid = sub.getId();
		dto->createdate = sub.getCreatedate();
		dto->createman = sub.getCreateman();
		dto->updatedate = sub.getUpdatedate();
		dto->updateman = sub.getUpdateman();
		dto->fylb = sub.getFylb();
		dto->fyje = sub.getFyje();
		dto->ffrs = sub.getFfrs();
		dto->ffsj = sub.getFfsj();
		dto->ffybz = sub.getFybz();
		dto->bz = sub.getBz();
		dto->ormorgid = sub.getOrmorgid();
		pages->addData(dto);
	}
	return pages;
}

uint64_t ExpenseLedgerService::saveData(const ExpenseLedgerDTO::Wrapper& dto)
{
	ExpenseLedgerDO data;
	data.setName(dto->pimexpaccountname.getValue(""));
	data.setId(dto->pimexpaccountid.getValue(""));
	data.setUpdateman(dto->updateman.getValue(""));
	data.setUpdatedate(dto->updatedate.getValue(""));
	data.setCreateman(dto->createman.getValue(""));
	data.setCreatedate(dto->createdate.getValue(""));
	data.setFylb(dto->fylb.getValue(""));
	data.setFyje(dto->fyje.getValue(0));
	data.setFfrs(dto->ffrs.getValue(0));
	data.setFfsj(dto->ffsj.getValue(""));
	data.setFybz(dto->ffybz.getValue(""));
	data.setBz(dto->bz.getValue(""));
	ExpenseLedgerDAO dao;
	return dao.insert(data);
}

bool ExpenseLedgerService::removeData(String id)
{
	ExpenseLedgerDO data;
	data.setId(id);
	ExpenseLedgerDAO dao;
	return dao.deleteById(data)==1;
}
