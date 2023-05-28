#include "stdafx.h"
#include "LegalEntityMaiService.h"
#include "dao/LegalEntityMai/LegalEntityMaiDAO.h"

/* 法人主体维护Service层具体实现--（组织管理-数据设置-法人主体维护）--TripleGold */
LegalEntityMaiPageDTO::Wrapper LegalEntityMaiService::listAll(const LegalEntityMaiQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = LegalEntityMaiPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	LegalEntityMaiDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OrmsignorgDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (OrmsignorgDO sub : result)
	{
		auto dto = LegalEntityMaiDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, Id, ORMSIGNORGNAME, Name,ORGCODE, Code);
		/*ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, ORMSIGNORGID,
			UPDATEMAN, UPDATEMAN, CREATEMAN, CREATEMAN,
			CREATEDATE, CREATEDATE, ORMSIGNORGNAME, ORMSIGNORGNAME,
			UPDATEDATE, UPDATEDATE, ORGCODE, ORGCODE, ZZJC, ZZJC);*/
		pages->addData(dto);
	}
	return pages;
}

bool LegalEntityMaiService::updateData(const LegalEntityMaiDTO::Wrapper& dto)
{
	// 组装DO数据
	OrmsignorgDO data;
	/*data.setId(dto->ORMSIGNORGID.getValue(""));
	data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, ORMSIGNORGID, Name, ORMSIGNORGNAME, Code, ORGCODE);
	// 执行数据添加
	LegalEntityMaiDAO dao;
	return dao.update(data) == 1;
}

uint64_t LegalEntityMaiService::saveData(const LegalEntityMaiDTO::Wrapper& dto)
{
	// 组装DO数据
	OrmsignorgDO data;
	/*data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, ORMSIGNORGID, Name, ORMSIGNORGNAME, Code, ORGCODE);
	// 执行数据添加
	LegalEntityMaiDAO dao;
	return dao.insert(data);
}

bool LegalEntityMaiService::removeData(string id)
{
	LegalEntityMaiDAO dao;
	return dao.deleteById(id) == 1;
}

//bool LegalEntityMaiService::importFile()
//{
//	return true;
//}
//
//bool LegalEntityMaiService::exportFile()
//{
//	return true;
//}

