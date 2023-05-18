#pragma once
#ifndef _UPDATELEGALERSETINGMESSAGE_DO_
#define _UPDATELEGALERSETINGMESSAGE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UpdateLegalerSetingMessageDO {
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
public:
	UpdateLegalerSetingMessageDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
	}
};
#endif // !_UPDATELEGALERSETINGMESSAGE_DO_
