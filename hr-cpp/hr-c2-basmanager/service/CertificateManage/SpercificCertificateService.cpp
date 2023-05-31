#include "stdafx.h"
#include "SpercificCertificateService.h"
#include "../../dao/CertificateManage/SpercificCertificateDAO.h"

bool SpercificCertificateService::updateData(const SpercificCertificateDTO::Wrapper& dto)
{
	// 组装数据
	SpercificCertificateDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PimperSonName, pimperSonName, Zgzsbh, zgzsbh, Zslx, zslx, PimVocationalName, pimVocationalName,
		Zgsydw, zgsydw, regisNumber, REGISNUMBER, Zcdw, zcdw, SOCSECPAYUNIT, SOCSECPAYUNIT,
		BcardNumber, bcardNumber, Zghqrq, zghqrq, CSZCSJ, CSZCSJ, XZCSJ, XZCSJ, Sxrq, sxrq,
		NSQK, NSQK, SYQK, SYQK, ALTERATION, ALTERATION, PIMVOCATIONALID, PIMVOCATIONALID);

	SpercificCertificateDAO dao;
	
	// 更新成功返回true反之flase
	return dao.update(data) == 1;
}

SpercificCertificateDTO::Wrapper SpercificCertificateService::querySpercificCertificate(const SpercificCertificateQuery::Wrapper &query)
{
	SpercificCertificateDAO dao;

	auto dto = SpercificCertificateDTO::createShared();

	auto res = dao.querySpercificC(query);

	for (auto row : res)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, row, pimperSonName, PimperSonName, zgzsbh, Zgzsbh,
			zslx, Zslx,
			pimVocationalName, PimVocationalName,
			zgsydw, Zgsydw,
			REGISNUMBER, regisNumber,
			zcdw, Zcdw,
			SOCSECPAYUNIT, SOCSECPAYUNIT,
			bcardNumber, BcardNumber,
			zghqrq, Zghqrq,
			CSZCSJ, CSZCSJ,
			XZCSJ, XZCSJ,
			sxrq, Sxrq,
			NSQK, NSQK,
			SYQK, SYQK,
			ALTERATION, ALTERATION,
			PIMVOCATIONALID, PIMVOCATIONALID);
	}

	return dto;
}