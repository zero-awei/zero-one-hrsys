#pragma once
#ifndef _EMPLOYEEINFO_DO_
#define _EMPLOYEEINFO_DO_
#include "../DoInclude.h"
/**
 * 人员信息分页查询DO--(证书管理-分页查询员工信息列表)--weixiaoman
 */
class EmployeeInfoDO {
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 编号（唯一标识）
	CC_SYNTHESIZE(string, id, Id);
public:
	EmployeeInfoDO() {
		name = "";
		id = "";
	}
};
#endif // !_EMPLOYEEINFO_DO_


