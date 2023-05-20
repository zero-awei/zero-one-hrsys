#pragma once
#ifndef _EMPLOYEEINFO_DO_
#define _EMPLOYEEINFO_DO_
#include "../DoInclude.h"

class EmployeeInfoDO {
	// ÐÕÃû
	CC_SYNTHESIZE(string, name, Name);
public:
	EmployeeInfoDO() {
		name = "";
	}
};

#endif // !_EMPLOYEEINFO_DO_


