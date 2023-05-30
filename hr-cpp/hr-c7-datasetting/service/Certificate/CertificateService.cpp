#include "stdafx.h"
#include "CertificateService.h"
#include "../../dao/Certificate/CertificateDAO.h"
CertificatePageDTO::Wrapper CertificateService::listAll(const CertificateQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CertificatePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CertificateDAO dao;
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
		auto dto = CertificateDTO::createShared();
		dto->seialno = sub.getseialNo();
		dto->pimqualtypename = sub.getpimQualTypeName();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, seialno, seialNo, pimqualtypename, pimQualTypeName);
		pages->addData(dto);

	}
	return pages;
}

uint64_t CertificateService::saveData(const CertificateDTO::Wrapper& dto)
{
	// 组装DO数据
	CertificateDO data;
	data.setseialNo(dto->seialno.getValue(1));
	data.setpimQualTypeName(dto->pimqualtypename.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, seialNo, seialno, pimQualTypeName, pimqualtypename);
	// 执行数据添加
	CertificateDAO dao;
	return dao.insert(data);
}

bool CertificateService::updateData(const CertificateDTO::Wrapper& dto)
{
	// 组装DO数据
	CertificateDO data;
	data.setseialNo(dto->seialno.getValue(1));
	data.setpimQualTypeName(dto->pimqualtypename.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, seialNo, seialno, pimQualTypeName, pimqualtypename);
	// 执行数据修改
	CertificateDAO dao;
	return dao.update(data) == 1;
}

bool CertificateService::removeData(uint64_t id)
{
	CertificateDAO dao;
	return dao.deleteById(id) == 1;
}
