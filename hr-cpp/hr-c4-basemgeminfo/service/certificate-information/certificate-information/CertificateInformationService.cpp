#include "stdafx.h"
#include "CertificateInformationService.h"
#include"../../../dao/certificate-information/certificate-information/CertificateInformationDAO.h"
#include "../../../domain/do/certificate-information/CertificateInformationDO.h"
//定义分页查询所有证书数据的函数listAll
CertificateInformationPageDTO::Wrapper CertificateInformationService::listAll(const CertificateInformationPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CertificateInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数,传递到dao层
	CertificateInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CertificateInformationDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (CertificateInformationDO sub : result)
	{
		auto dto = CertificateInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, zgzsbh, Zgzsbh, pimvocationalname, Pimvocationalname, zslx, Zslx, zghqrq, Zghqrq, zgsydw, Zgsydw, fzyxq, Fzyxq,pimpersonid, Pimpersonid );
		pages->addData(dto);
	}
	return pages;
}