#include "stdafx.h"
#include "RraineeService.h"
#include "domain/dto/RosterOfPer/RraineeDTO.h"


// 基础管理 ——人员花名册 ——见习员工 -- cpt

RraineePageDTO::Wrapper RraineeService::listAll(const RraineeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RraineePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//// 查询数据总条数
	//RraineeDAO dao;
	//uint64_t count = dao.count(query);
	//if (count <= 0)
	//{
	//	return pages;
	//}

	//// 分页查询数据
	//pages->total = count;
	//pages->calcPages();
	//list<RraineeDO> result = dao.selectWithPage(query);
	//// 将DO转换成DTO
	//for (RraineeDO sub : result)
	//{
	//	auto dto = RraineeDTO::createShared();
	//	// 		dto->id = sub.getId();
	//	// 		dto->name = sub.getName();
	//	// 		dto->sex = sub.getSex();
	//	// 		dto->age = sub.getAge();
	//	ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
	//		pages->addData(dto);

	//}
	return pages;
}
