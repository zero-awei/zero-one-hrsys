#include "stdafx.h"
#include "CertificateTypeService.h"
#include "../../dao/CertificateManage/CertificateTypeDAO.h"
/**
* 证书类型查询传输对象--(证书管理-查询证书类型列表)--weixiaoman
*/
CertificateTypePageDTO::Wrapper CertificateTypeService::listAll(const CertificateTypeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CertificateTypePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CertificateTypeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CertificateTypeDO> result = dao.selectWithPage(query);
	//list<EmployeeInfoDO> result = dao.selectByName(query->name);
	// 将DO转换成DTO
	for (CertificateTypeDO sub : result)
	{
		auto dto = CertificateTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, certype, CerType,id,Id);
		pages->addData(dto);
	}
	return pages;
}
