#pragma once
#ifndef _LEGALENTITYMAIDAO_H_
#define _LEGALENTITYMAIDAO_H_
#include "BaseDAO.h"
#include "domain/query/LegalEntityMai/LegalEntityMaiQuery.h"
#include "domain/do/LegalEntityMai/ormsignorgDO.h"

/* 法人主体维护DAO层设计--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const LegalEntityMaiQuery::Wrapper& query);
	// 分页查询数据
	list<OrmsignorgDO> selectWithPage(const LegalEntityMaiQuery::Wrapper& query);
	// 通过名称查询数据
	//list<OrmsignorgDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const OrmsignorgDO& iObj);
	// 修改数据
	int update(const OrmsignorgDO& uObj);
	// 通过ID删除数据
	int deleteById(string id);
};

#endif // !_LEGALENTITYMAIDAO_H_