#pragma once
#ifndef _TEMPORARYSTAFF_SERVICE_
#define _TEMPORARYSTAFF_SERVICE_
#include <list>
#include "domain/vo/RosterOfPer/TemporaryStaffVO.h"
#include "domain/dto/RosterOfPer/TemporaryStaffDTO.h"
#include "domain/query/RosterOfPer/TemporaryStaffQuery.h"
class TemporaryStaffService {
public:
	TemporaryStaffPageDTO::Wrapper listAll(const TempStaffQuery::Wrapper& query);
};



#endif // !_TEMPORARYSTAFF_SERVICE_

