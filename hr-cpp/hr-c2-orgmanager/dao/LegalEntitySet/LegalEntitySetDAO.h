#pragma once
/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/
#ifndef _LEGALENTITYSET_DAO_
#define _LEGALENTITYSET_DAO_
#include "BaseDAO.h"
#include "domain/do/LegalEntitySet/LegalEntitySetDO.h"
#include "domain/query/LegalEntitySet/LegalEntitySetQuery.h"
/**
 * 示例表数据库操作实现
 */
class LegalEntitySetDAO : public BaseDAO
{
public:
	// 统计数据条数
	//uint64_t count(const LegalEntitySetQuery::Wrapper& query);
	// 分页查询数据
	//list<LegalEntitySetDO> selectWithPage(const LegalEntitySetQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const LegalEntitySetDO& iObj);
	// 修改数据
	int update(const LegalEntitySetDO& uObj);
	// 法人主体名称下拉列表  
	std::list<LegalEntitySetDO> legalerNamePullDownList();
	// 统计数据条数
	uint64_t count(const LegalEntitySetQuery::Wrapper& query);
	// 分页查询数据
	list<LegalEntitySetDO> selectWithPage(const LegalEntitySetQuery::Wrapper& query);
	
};
#endif // !_LEGALENTITYSET_DAO_
