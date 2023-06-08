#include "stdafx.h"
#include "EmployeePageService.h"
#include "../../dao/RosterOfPer/EmployeePageDAO.h"
#include "Macros.h"

EmployeePageDTO::Wrapper EmployeePageService::listAll(const EmployeePageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = EmployeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	EmployeePageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RosterPersonDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RosterPersonDO sub : result)
	{
		auto dto = EmployeeDTO::createShared();

		EMPLOYEEPAGE_DO_TO_DTO_A
		EMPLOYEEPAGE_DO_TO_DTO_B
		EMPLOYEEPAGE_DO_TO_DTO_C
		pages->addData(dto);

	}
	
	return pages;
}


