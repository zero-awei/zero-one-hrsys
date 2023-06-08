#include "stdafx.h"
#include "ExportEmployeeService.h"
#include "../../dao/RosterOfPer/ExportEmployeeDAO.h"

ExportEmployeeDTO::Wrapper ExportEmployeeService::listAll(const ExportEmployeeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ExportEmployeeDTO::createShared();
	//pages->pageIndex = query->pageIndex;
	//pages->pageSize = query->pageSize;

	//// 查询数据总条数
	//SampleDAO dao;
	//uint64_t count = dao.count(query);
	//if (count <= 0)
	//{
	//	return pages;
	//}

	//// 分页查询数据
	//pages->total = count;
	//pages->calcPages();
	//list<SampleDO> result = dao.selectWithPage(query);
	//// 将DO转换成DTO
	//for (SampleDO sub : result)
	//{
	//	auto dto = SampleDTO::createShared();
	//	// 		dto->id = sub.getId();
	//	// 		dto->name = sub.getName();
	//	// 		dto->sex = sub.getSex();
	//	// 		dto->age = sub.getAge();
	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
	//		pages->addData(dto);

	//}
	return pages;
}


