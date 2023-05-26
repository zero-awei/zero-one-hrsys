#include "stdafx.h"
#include "TemporaryStaffService.h"
#include "../../dao/RosterOfPer/TemporaryStaffDAO.h"
/**
* 挂职人员service--(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
*/
TemporaryStaffPageDTO::Wrapper TemporaryStaffService::listAll(const TempStaffQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = TemporaryStaffPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	TemporaryStaffDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<TemporaryStaffDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (TemporaryStaffDO sub : result)
	{
		auto dto = TemporaryStaffDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, ygbh, name, pimPersonName, empStatus,
			ygzt,tempStatus, gzzt, tempOrg, gzzz,
			tempDept, gzbm, tempStartTime, gzkssj,tempEndTime, gzjssj);
		pages->addData(dto);

	}
	return pages;
}
