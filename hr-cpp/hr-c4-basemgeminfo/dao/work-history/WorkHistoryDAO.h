#pragma once
#ifndef _WORKHISTORY_DAO_H_
#define _WORKHISTORY_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/work-history/WorkHistoryDO.h"
#include "../../domain/query/work-history/WorkHistoryQuery.h"

class WorkHistoryDAO : public BaseDAO
{
public:
	
	list<WorkHistoryDO> selectDetail(const WorkHistoryQuery::Wrapper& query);
	
	int update(const WorkHistoryDO& uObj);
};

#endif // 

