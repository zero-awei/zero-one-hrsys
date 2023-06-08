/*
人员花名册-离退休人员-分页查询员工列表--pine
*/
#include "stdafx.h"
#include "CheckRetiresListService.h"
#include "../../dao/RosterOfPer/CheckRetiresListDAO.h"

CheckRetiresListPageDTO::Wrapper CheckRetiresListService::listAll(const CheckRetiresListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CheckRetiresListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CheckRetiresListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RetiredEmployeesDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RetiredEmployeesDO sub : result)
	{
		auto dto = CheckRetiresListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ygbh, ygbh,idAndName, idAndName, pimpersonname, pimpersonname, xb, xb, nj, nj, postaladdress, postaladdress, retiPlace, retiPlace, jtlxr, jtlxr, jtlxrdh, jtlxrdh, zz, zz, bm, bm,
			rank, rank, yzw, yzw, ygw, ygw, txdq, txdq, sjtxrq, sjtxrq, lxdh, lxdh, spdylje, spdylje, pimpersonid, pimpersonid)
		pages->addData(dto);
	}
	return pages;
}


