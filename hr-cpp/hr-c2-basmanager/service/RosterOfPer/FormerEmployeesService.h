#pragma once
/**
 * 人员花名册 - 离职人员 - 楚孟献
 */
#ifndef _FORMEREMPLOYEES_SERVICE_
#define _FORMEREMPLOYEES_SERVICE_
#include <list>
#include "domain/vo/RosterOfPer/FormerEmployeesVO.h"
#include "domain/dto/RosterOfPer/FormerEmployeesDTO.h"
#include "domain/query/RosterOfPer/FormerEmployeesQuery.h"
class FormerEmployeesService {
public:
	FormerEmployeesPageDTO::Wrapper listAll(const FormerEmployeesQuery::Wrapper& query);

	std::string exportData(const FormerEmployeesQuery::Wrapper& query);
};

#endif // !_FORMEREMPLOYEES_SERVICE_
