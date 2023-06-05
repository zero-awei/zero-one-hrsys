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
新增法人设置（支持批量新增） `LegalEntitySet`
*/


LegalEntitySetPullDownDTO::Wrapper LegalEntitySetService::legalEntityPulldownList() {
	LegalEntitySetDAO dao;
	std::list<LegalEntitySetDO> date = dao.legalerNamePullDownList();
	auto dto = LegalEntitySetPullDownDTO::createShared();
	for (auto it : date) {
		string str = it.getORMSIGNORGID();
		dto->legalEntitySetPullDownList->push_back(LegalEntitySetDTO::createShared(str));
	}
	return dto;
}

uint64_t LegalEntitySetService::insertData(const LegalEntitySetAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	//雪花算法 生成唯一标识
	SnowFlake snowid(1, 2); 
	// 组装DO数据
	LegalEntitySetDO data; 
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CONTRACTSIGNORGNAME, contractsignorgname, ORMORGID, ormorgid, ORMSIGNORGID, ormsignorgid, ISDEFAULTSIGNORG, isdefaultsignorg)
	SimpleDateTimeFormat time;
	data.setCONTRACTSIGNORGID(to_string(snowid.nextId()));
	data.setCREATEDATE(time.format());
	data.setCREATEMAN(payload.getUsername());
	data.setUPDATEDATE(time.format());
	data.setUPDATEMAN(payload.getUsername());
	//data.setSIGNORGID(payload->getId());
	// 执行数据添加
	LegalEntitySetDAO dao;
	return dao.insert(data);
}

bool LegalEntitySetService::updateData(const LegalEntitySetUpdateDTO::Wrapper& dto) {
	// 组装DO数据
	LegalEntitySetDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CONTRACTSIGNORGNAME, contractsignorgname,  ORMORGID, ormorgid, ORMSIGNORGID, ormsignorgid, ISDEFAULTSIGNORG, isdefaultsignorg)
	// 执行数据修改
	LegalEntitySetDAO dao;
	return dao.update(data);
}

// 删除数据 
//bool LegalEntitySetService::removeData(uint64_t id)
//{
//	LegalEntitySetDAO dao;
//	return dao.deleteById(id) == 1;
//}


/* ----------------------------------法人主体维护Service层具体实现--（组织管理-数据设置-法人主体维护）--TripleGold ------------------------------------------------*/
LegalEntitySetQueryPageDTO::Wrapper LegalEntitySetService::listAll(const LegalEntitySetQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = LegalEntitySetQueryPageDTO::createShared();
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
		auto dto = LegalEntitySetQueryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, contractsignorgid, CONTRACTSIGNORGID, contractsignorgname, CONTRACTSIGNORGNAME, ormsignorgid, ORMSIGNORGID, ormorgid, ORMORGID, isdefaultsignorg, ISDEFAULTSIGNORG);
		pages->addData(dto);
	}
	return pages;
}