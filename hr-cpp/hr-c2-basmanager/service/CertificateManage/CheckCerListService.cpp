/*
证书管理-分页查询证书列表--pine
*/
#include "stdafx.h"
#include "CheckCerListService.h"
#include "../../dao/CertificateManage/CheckCerListDAO.h"

CheckCerListPageDTO::Wrapper CheckCerListService::listAll(const CheckCerListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CheckCerListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CheckCerListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CertificateDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (CertificateDO sub : result)
	{
		auto dto = CheckCerListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		//// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ygbh, Ygbh, nameOfPAndV, NameOfPAndV, pimperSonName, PimperSonName, ygzt, Ygzt, zz, ZZ, zgzsbh, ZGZSBH, bcardNumber, BcardNumber,
			pimVocationalName, PimVocationalName, zslx, Zslx, zghqrq, Zghqrq, zgsydw, Zgsydw, zcdw, Zcdw, fzyxq, Fzyxq, sxrq, Sxrq, pimpersonid, PIMPERSONID, regisnumber, REGISNUMBER, socsecpayunit, SOCSECPAYUNIT, cszcsj, CSZCSJ, xzcsj, XZCSJ, pimvocationalid, Pimvocationalid)
		pages->addData(dto);

	}
	return pages;
}


