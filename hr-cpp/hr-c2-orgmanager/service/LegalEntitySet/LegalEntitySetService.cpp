#include "stdafx.h"
#include "LegalEntitySetService.h"
#include "dao/LegalEntitySet/LegalEntitySetDAO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/


LegalEntitySetPullDownDTO::Wrapper LegalEntitySetService::legalEntityPulldownList() {
	auto dto = LegalEntitySetPullDownDTO::createShared();
	LegalEntitySetDAO dao;
	std::list<LegalEntitySetDO> date = dao.legalerNamePullDownList();
	for (auto it : date) {
		string str = it.getORMSIGNORGNAME();
		dto->legalEntitySetPullDownList->push_back(LegalEntitySetDTO::createShared(str));
	}
	return dto;
}

uint64_t LegalEntitySetService::insertData(const LegalEntitySetDTO::Wrapper& dto)
{
	SnowFlake snowid(1, 2);
	// 组装DO数据
	LegalEntitySetDO data;
	//data.setORMSIGNORGID(dto->ormsignorgid.getValue(to_string(snowid.nextId())));
	//data.setORMSIGNORGNAME(dto->ormsignorgname.getValue(""));
	////data.setCONTRACTSIGNORGNAME(dto->contractsignorgname.getValue(to_string(snowid.nextId())));输入 dto 前端
	//data.setISDEFAULTSIGNORG(dto->isdefaultsignorg.getValue(""));  // 后端 唯一 id 
	// 输入 dto 前端     
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ORMSIGNORGNAME, ormsignorgname, CONTRACTSIGNORGNAME, contractsignorgname, ISDEFAULTSIGNORG, isdefaultsignorg)
		/*ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ORMSIGNORGID, ormsignorgid, ORMSIGNORGNAME, ormsignorgname,
			CONTRACTSIGNORGNAME, contractsignorgname)*/
		
	data.setORMSIGNORGID(to_string(snowid.nextId()));
	data.setCONTRACTSIGNORGID(to_string(snowid.nextId()));
	// 执行数据添加
	LegalEntitySetDAO dao;
	dao.insert1(data);
	return dao.insert2(data);
}

bool LegalEntitySetService::updateData(const LegalEntitySetDTO::Wrapper& dto) {
	// 组装DO数据
	LegalEntitySetDO data;
	/*
	data.setORMSIGNORGID(dto->ormsignorgid.getValue(""));
	data.setORMSIGNORGNAME(dto->ormsignorgname.getValue(""));
	data.setCONTRACTSIGNORGNAME(dto->contractsignorgname.getValue(""));
	data.setISDEFAULTSIGNORG(dto->isdefaultsignorg.getValue(1));
	*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ORMSIGNORGID, ormsignorgid, ORMSIGNORGNAME, ormsignorgname, CONTRACTSIGNORGNAME, contractsignorgname)
	// 执行数据修改
	LegalEntitySetDAO dao;
	return dao.update(data) == 1;
}

// 删除数据 
//bool LegalEntitySetService::removeData(uint64_t id)
//{
//	LegalEntitySetDAO dao;
//	return dao.deleteById(id) == 1;
//}


/* ----------------------------------法人主体维护Service层具体实现--（组织管理-数据设置-法人主体维护）--TripleGold ------------------------------------------------*/
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
	list<LegalEntitySetDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (LegalEntitySetDO sub : result)
	{
		auto dto = LegalEntitySetDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ormsignorgid, ORMSIGNORGID, contractsignorgname, CONTRACTSIGNORGNAME, ormsignorgname, ORMSIGNORGNAME, isdefaultsignorg, ISDEFAULTSIGNORG);
		pages->addData(dto);
	}
	return pages;
}