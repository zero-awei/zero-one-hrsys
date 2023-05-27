#pragma once
#ifndef _FORMEREMPLOYEES_SERVICE_
#define _FORMEREMPLOYEES_SERVICE_
#include <list>
#include "domain/vo/RosterOfPer/FormerEmployeesVO.h"
#include "domain/dto/RosterOfPer/FormerEmployeesDTO.h"
#include "domain/query/RosterOfPer/FormerEmployeesQuery.h"
class FormerEmployeesService {
public:
	FormerEmployeesPageDTO::Wrapper listAll(const FormerEmployeesQuery::Wrapper& query);
};



#endif // !_FORMEREMPLOYEES_SERVICE_
