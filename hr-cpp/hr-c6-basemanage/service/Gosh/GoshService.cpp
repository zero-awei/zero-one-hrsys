#include "stdafx.h"
#include "GoshService.h"
#include "../arch-demo/dao/sample/SampleDAO.h"
#include "domain/dto/Gosh/ContractDTO.h"

ContractDTO_gs::Wrapper GoshService::listAll(const ContractQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ContractPageDTO_gs::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	SampleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<SampleDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (SampleDO sub : result)
	{
		auto dto = ContractDTO_gs::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, type, TYPE, variety, VARIETY, date, DATE, condition, CONDITION, department_m, DEPATMENT_M, department_c, DEPATMENT_C, );
		pages->addData(dto);

	}
	return pages;
}

uint64_t GoshService::saveData(const ContractDTO_gs::Wrapper& dto)
{
	// 组装DO数据
	SampleDO data;
	data.setName(dto->name.getValue(""));
	data.setSex(dto->sex.getValue(""));
	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
		// 执行数据添加
		SampleDAO dao;
	return dao.insert(data);
}

bool GoshService::updateData(const ContractDTO_gs::Wrapper& dto)
{
	// 组装DO数据
	SampleDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)
		// 执行数据修改
		SampleDAO dao;
	return dao.update(data) == 1;
}

bool GoshService::removeData(uint64_t id)
{
	SampleDAO dao;
	return dao.deleteById(id) == 1;
}