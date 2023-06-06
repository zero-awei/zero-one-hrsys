#pragma once
#ifndef _CONTRACTDAO_H_
#define _CONTRACTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/ContractType/ContractTypeDO.h"
#include "../../domain/query/ContractType/ContractTypeQuery.h"

class ContractTypeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ContractTypeQuery::Wrapper& query);
	// 分页查询数据
	list<ContractTypeDO> selectWithPage(const ContractTypeQuery::Wrapper& query);
	// 通过姓名查询数据
	list<ContractTypeDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const ContractTypeDO& iObj);
	// 修改数据
	int update(const ContractTypeDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};

#endif // !_CONTRACTDAO_H_