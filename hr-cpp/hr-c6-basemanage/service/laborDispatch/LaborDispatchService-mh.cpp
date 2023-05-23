/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/25 21:08:20

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
#include "LaborDispatchService-mh.h"
#include "domain/do/laborDispatch/LaborDispatchDO.h"
#include "dao/laborDispatch/LaborDispatchDAO-mh.h"
#include "domain/dto/LaborDispatch/LaborDispatchDTO.h"



LaborDispatchPageDTO::Wrapper LaborDispatchService::listAll_ld(const LaborDispatchQuery::Wrapper& query)
{
	//构建返回对象
	auto pages = LaborDispatchPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//查询数据总条数
	LaborDispatchDAO dao;
	uint64_t count = dao.count_ld(query);
	if (count <= 0)
	{
		return pages;
	}

	//分页插叙数据
	pages->total = count;
	pages->calcPages();
	list<LaborDispatchDO> result = dao.selectWrithPage_ld(query);
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
