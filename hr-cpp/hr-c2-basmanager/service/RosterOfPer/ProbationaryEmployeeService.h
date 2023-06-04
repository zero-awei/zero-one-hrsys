#pragma once
/**
 * 人员花名册 - 试用人员Service实现 - 楚孟献
 */

#ifndef __PROBATIONARY_EMPLOYEE_SERVICE_
#define __PROBATIONARY_EMPLOYEE_SERVICE_
#include <list>
#include "domain/vo/RosterOfPer/ProbationaryEmployeeVO.h"
#include "domain/dto/RosterOfPer/ProbationaryEmployeeDTO.h"
#include "domain/query/RosterOfPer/ProbationaryEmployeeQuery.h"
class ProbationaryEmployeeService {
public:
	ProbationaryEmployeePageDTO::Wrapper listAll(const ProbationaryEmployeeQuery::Wrapper& query);
	std::string exportData(const ProbationaryEmployeeQuery::Wrapper& query);
};



#endif // !_ProbationaryEmployee_SERVICE_
