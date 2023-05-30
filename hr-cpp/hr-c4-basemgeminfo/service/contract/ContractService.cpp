#include "stdafx.h"
#include "ContractService.h"
#include"../../dao/contract/ContractDAO.h"

ContractPageDTO::Wrapper ContractService::listAll(const ContractQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ContractPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ContractDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ContractDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ContractDO sub : result)
	{
		auto dto = ContractDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, PIMPERSONID, _PIMPERSONID, HTBH, _HTBH, HTLX, _HTLX, CONTRACTTYPE, _CONTRACTTYPE, QSRQ, _QSRQ, JSRQ, _JSRQ, HTZT, _HTZT, SYDQSJ, _SYDQSJ);
		pages->addData(dto);

	}
	return pages;
}