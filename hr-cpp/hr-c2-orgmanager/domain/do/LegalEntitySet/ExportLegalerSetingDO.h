#pragma once
#ifndef _EXPORTLEGALERSETTING_DO_
#define _EXPORTLEGALERSETTING_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ExportLegalerSetingDO {
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
public:
	ExportLegalerSetingDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};
#endif // !_EXPORTLEGALERSETTING_DO_
