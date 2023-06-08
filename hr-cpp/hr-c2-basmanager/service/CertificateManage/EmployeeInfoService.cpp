#include "stdafx.h"
#include "EmployeeInfoService.h"
#include "../../dao/CertificateManage/EmployeeInfoDAO.h"
/**
 * 人员信息分页查询service--(证书管理-分页查询员工信息列表)--weixiaoman
 */
EmployeeInfoPageDTO::Wrapper EmployeeInfoService::listAll(const EmployeeInfoQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = EmployeeInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	EmployeeInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<EmployeeInfoDO> result = dao.selectWithPage(query);
	//list<EmployeeInfoDO> result = dao.selectByName(query->name);
	// 将DO转换成DTO
	for (EmployeeInfoDO sub : result)
	{
		auto dto = EmployeeInfoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name,id,Id);
		pages->addData(dto);
	}
	return pages;
}
