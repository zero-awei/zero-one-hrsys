/*
 Copyright Muggle. All rights reserved.

 @Author: Muggle
 @Date: 2023/05/20 0:17:17

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
#include "laborDispatchService-mg.h"
#include "../../dao/laborDispatch/LaborDispatchDAO-mg.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO.h"
//#include "domain/dto/LaborDispatch/LaborDispatchDTO-mg.h"

LaborDispatchPageDTO::Wrapper LaborDispatchMService::ListAll(const LaborDispatchMQuery::Wrapper& query)
{
	auto pages = LaborDispatchPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	LaborDispatchMDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	//分页插叙数据
	pages->total = count;
	pages->calcPages();
	list<LaborDispatchDO> result = dao.selectByCorporateName(query);
	//将DO转换成DTO
	for (LaborDispatchDO sub : result)
	{
		auto dto = LaborDispatchDTO::createShared();
		dto->name = sub.getName();
		dto->id = sub.getId();
		dto->createdate = sub.getCreatedate();
		dto->createman = sub.getCreateman();
		dto->updatedate = sub.getUpdatedate();
		dto->jyfw = sub.getJyfw();
		dto->lxdz = sub.getLxdz();
		dto->lxfs = sub.getLxfs();
		dto->lxr = sub.getLxr();
		dto->gsjj = sub.getGsjj();
		dto->pimpersonid = sub.getPimpersonid();
		dto->ormorgid = sub.getOrmorgid();
		dto->regcapital = sub.getRegcapital();
		dto->legalperson = sub.getLegalperson();
		pages->addData(dto);
	}
	return pages;
}

bool LaborDispatchMService::updateData(const LaborDispatchDTO::Wrapper& dto)
{
	// 组装DO数据
	LaborDispatchDO data;
	data.setName(dto->name.getValue(""));
	data.setId(dto->id.getValue(""));
	data.setCreatedate(dto->createdate.getValue(""));
	data.setCreateman(dto->createdate.getValue(""));
	data.setUpdateman(dto->updateman.getValue(""));
	data.setUpdatedate(dto->updatedate.getValue(""));
	data.setJyfw(dto->jyfw.getValue(""));
	data.setLxdz(dto->lxdz.getValue(""));
	data.setLxfs(dto->lxfs.getValue(""));
	data.setLxr(dto->lxr.getValue(""));
	data.setGsjj(dto->gsjj.getValue(""));
	data.setPimpersonid(dto->pimpersonid.getValue(""));
	data.setOrmorgid(dto->ormorgid.getValue(""));
	data.setRegcapital(dto->regcapital.getValue(""));
	data.setLegalperson(dto->legalperson.getValue(""));
	cout << "data is " << data.getName() << ":" << dto->name.getValue("") << endl;
	LaborDispatchMDAO dao;
	return dao.update(data) == 1;
}


