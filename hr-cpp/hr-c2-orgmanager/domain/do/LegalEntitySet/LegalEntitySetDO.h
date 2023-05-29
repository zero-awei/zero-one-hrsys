#pragma once

/*
*（	数据设置——法人主体设置——导出法人主体设置 (导出页面在前端完成) --cpt
*/

#ifndef _LEGALENTITY_DO_
#define _LEGALENTITY_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class LegalEntitySetDO {
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
public:
	LegalEntitySetDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};
#endif // !_LEGALENTITY_DO_
