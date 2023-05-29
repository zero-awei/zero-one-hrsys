#pragma once
#ifndef _CONTRACTDAO_H_
#define _CONTRACTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/contractType/ContractTypeDO.h"
#include "../../domain/query/contractType/ContractTypeQuery.h"

class ContractTypeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ContractTypeQuery::Wrapper& query);
	// 分页查询数据
	list<ContractTypeDO> selectWithPage(const ContractTypeQuery::Wrapper& query);
};

#endif // !_CONTRACTDAO_H_