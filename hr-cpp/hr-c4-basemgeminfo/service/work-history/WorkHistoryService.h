#pragma once
#ifndef _WORKHISTORY_SERVICE_H_
#define _WORKHISTORY_SERVICE_H_
#include "domain/vo/work-history/ModWorkHistoryVO.h"
#include "domain/vo/work-history/WorkHistoryVO.h"
#include "domain/query/work-history/WorkHistoryQuery.h"
#include "domain/dto/work-history/ModWorkHistoryDTO.h"
#include "domain/dto/work-history/WorkHistoryDTO.h"

class WorkHistoryService
{
public:
	WorkHistoryDTO::Wrapper listDetail(const WorkHistoryQuery::Wrapper& query);
	// 
	bool updateData(const WorkHistoryDTO::Wrapper& dto);
};

#endif // 
