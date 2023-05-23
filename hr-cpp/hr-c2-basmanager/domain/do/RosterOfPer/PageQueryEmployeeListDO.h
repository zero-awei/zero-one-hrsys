#pragma once
#ifndef _PAGEQUERYEMPLOYEELIST_DO_
#define _PAGEQUERYEMPLOYEELIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class PageQueryEmployeeListDO{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);

public:
	PageQueryEmployeeListDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};
#endif // !_PAGEQUERYEMPLOYEELIST_DO_
