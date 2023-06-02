#pragma once
#ifndef  _CONTRACTMANAGERDAO_H_
#define  _CONTRACTMANAGERDAO_H_

#include "BaseDAO.h"
#include "domain/query/RetirementQuery/contractManagerQuery.h"
#include "domain/do/retirement/contractManagerDO.h"
#include <string>

class ContractManagerDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const contractManagerQuery::Wrapper& query);
	//分页查询数据
	list<contractManagerDO> selectWithPage(const contractManagerQuery::Wrapper& query);

};

#endif // ! _CONTRACTMANAGERDAO_H_
