/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "SampleService.h"
#include "../../dao/sample/SampleDAO.h"
#include "domain/dto/sample/SampleDTO.h"

SamplePageDTO::Wrapper SampleService::listAll(const SampleQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SamplePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	SampleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<SampleDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (SampleDO sub : result)
	{
		auto dto = SampleDTO::createShared();
// 		dto->id = sub.getId();
// 		dto->name = sub.getName();
// 		dto->sex = sub.getSex();
// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
		pages->addData(dto);
		
	}
	return pages;
}

uint64_t SampleService::saveData(const SampleDTO::Wrapper& dto)
{
	// ��װDO����
	SampleDO data;
 	data.setName(dto->name.getValue(""));
 	data.setSex(dto->sex.getValue(""));
 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
	// ִ���������
	SampleDAO dao;
	return dao.insert(data);
}

bool SampleService::updateData(const SampleDTO::Wrapper& dto)
{
	// ��װDO����
	SampleDO data;
// 	data.setId(dto->id.getValue(0));
// 	data.setName(dto->name.getValue(""));
// 	data.setSex(dto->sex.getValue(""));
// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
	// ִ�������޸�
	SampleDAO dao;
	return dao.update(data) == 1;
}

bool SampleService::removeData(uint64_t id)
{
	SampleDAO dao;
	return dao.deleteById(id) == 1;
}
