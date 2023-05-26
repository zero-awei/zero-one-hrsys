#pragma once
#ifndef _Gosh_DO_
#define _Gosh_DO_
#include "../DoInclude.h"
#include "../hr-sample/Macros.h"

/**
 * 示例数据库实体类
 */
class ContractDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	//合同类别
	CC_SYNTHESIZE(string, type, Type);
	//合同类型
	CC_SYNTHESIZE(string, variety, Variety);
	//起始日期
	CC_SYNTHESIZE(string, date, Date);
	//合同状态
	CC_SYNTHESIZE(string, condition, Condition);
	//合同管理单位
	CC_SYNTHESIZE(string, department_m, Department_m);
	//合同签订单位
	CC_SYNTHESIZE(string, department_c, Department_c);
	//合同到期时间
	CC_SYNTHESIZE(string, date_end, Date_end);
	//备注
	CC_SYNTHESIZE(string, tip, Tip);
public:
	ContractDO() {
		id = 0;
		name = "";
		type = "";
		variety = "";
		date= "";
		condition = "";
		department_m = "";
		department_c = "";
		date_end = "";
		tip = "";
	}
};

#endif 
