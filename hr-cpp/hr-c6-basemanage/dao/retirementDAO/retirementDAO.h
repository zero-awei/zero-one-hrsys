#pragma once
#ifndef _RETIREMENTDAO_H_
#define _RETIREMENTDAO_H_

#include "BaseDAO.h"
#include "domain/query/RetirementQuery/RetirementQuery.h"
#include "domain/do/retirement/retirementDO.h"
#include <string>

class RetirementDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const RetirementQuery_gan::Wrapper& query);
	//分页查询数据
	list<retirementDO> selectWithPage(const RetirementQuery_gan::Wrapper& query);

};


#endif // !_RETIREMENTDAO_H_
