#include "stdafx.h"
#include "FormerEmployeesService.h"
#include "../../dao/RosterOfPer/FormerEmployeesDAO.h"
FormerEmployeesPageDTO::Wrapper FormerEmployeesService::listAll(const FormerEmployeesQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = FormerEmployeesPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	FormerEmployeesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<FormerEmployeesDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (FormerEmployeesDO sub : result)
	{
		auto dto = FormerEmployeesDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, ygbh, name, pimPersonName, 
			sex, sex, phoneNumber, lxdh, chushengriqi, csrq,
			organization, organizationName, department, bm, rank, rank,
			mail_address, postalAddress, family_contact, jtlxr, family_contact_number, jtlxrdh);
		pages->addData(dto);

	}
	return pages;
}