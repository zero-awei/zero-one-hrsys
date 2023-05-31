#include "stdafx.h"
#include "LegalEntitySetService.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "dao/LegalEntitySet/LegalEntitySetDAO.h"

/* 法人主体维护Service层具体实现--（组织管理-数据设置-法人主体维护）--TripleGold */
LegalEntitySetPageDTO::Wrapper LegalEntitySetService::listAll(const LegalEntitySetQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = LegalEntitySetPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	LegalEntitySetDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<QueryLegalEntitySetDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (QueryLegalEntitySetDO sub : result)
	{
		auto dto = LegalEntitySetQueryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, CONTRACTSIGNORGID, Id, ORGNAME, OrgName, ORMSIGNORGNAME, LEMName, ISDEFAULTSIGNORG, Defa);
		pages->addData(dto);
	}
	return pages;
}
