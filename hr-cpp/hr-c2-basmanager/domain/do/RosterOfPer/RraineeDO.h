#pragma once
#ifndef _RRAINEE_DO_
#define _RRAINEE_DO_
#include "../DoInclude.h"

/**
 *  基础管理 —— 人员花名册 —— 见习员工实体类  ——Cpt
 */
class ExportEmployeeDO {
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
public:
	ExportEmployeeDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};

#endif // !_RRAINEE_DO_
