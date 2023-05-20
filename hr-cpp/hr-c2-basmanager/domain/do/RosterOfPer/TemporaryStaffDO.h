#pragma once
#ifndef _TEMPORARYSTAFF_DO_
#define _TEMPORARYSTAFF_DO_
#include "../DoInclude.h"

/**
* 挂职人员数据库实体类
*/
class TemporaryStaffDO {
	//员工编号
	CC_SYNTHESIZE(string, id, Id);
	//员工姓名
	CC_SYNTHESIZE(string, name, Name);
	//员工状态
	CC_SYNTHESIZE(string, empStatus, EmpStatus);
	//挂职状态
	CC_SYNTHESIZE(string, tempStatus, TempStatus);
	//挂职组织
	CC_SYNTHESIZE(string, tempOrg, TempOrg);
	//挂职部门
	CC_SYNTHESIZE(string, tempDept, TempDept);
	//挂职开始时间
	CC_SYNTHESIZE(string, tempStartTime, TempStartTime);
	//挂职结束时间
	CC_SYNTHESIZE(string, tempEndTime, TempEndTime);
public:
	TemporaryStaffDO() {
		id = "0";
		name = "";
		empStatus = "在职";
		tempStatus = "挂职进";
		tempOrg = "";
		tempDept = "";
		tempStartTime = "";
		tempEndTime = "";
	}
};





#endif // !_TEMPORARYSTAFF_DO_
