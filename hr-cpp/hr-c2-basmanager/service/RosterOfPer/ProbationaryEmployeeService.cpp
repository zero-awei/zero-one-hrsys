#include "stdafx.h"
#include "ProbationaryEmployeeService.h"
#include "../../dao/RosterOfPer/ProbationaryEmployeeDAO.h"

ProbationaryEmployeePageDTO::Wrapper ProbationaryEmployeeService::listAll(const ProbationaryEmployeeQuery::Wrapper& query)
{
	auto pages = ProbationaryEmployeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ProbationaryEmployeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}


	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProbationaryEmployeeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ProbationaryEmployeeDO sub : result)
	{
		auto dto = ProbationaryEmployeeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, YGBH, name, PIMPERSONNAME,
			zz, ORMORGNAME, bm, ORMORGSECTORNAME,
			zw, ZW, gw, ORMPOSTNAME, rzsj, RZSJ,
			time, SYDQ);
		pages->addData(dto);
	}

	return pages;
}

