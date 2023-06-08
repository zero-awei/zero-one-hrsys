#pragma once

#ifndef _CONTRACTMANAGERDO_H_
#define _CONTRACTMANAGERDO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class contractManagerDO
{
	// 员工编号1
	CC_SYNTHESIZE(string, id, Id);
	// 员工姓名2
	CC_SYNTHESIZE(string, name, Name);
	// 员工所属单位3
	CC_SYNTHESIZE(string, Employee_unit, Employee_Unit);
	// 员工状态4
	CC_SYNTHESIZE(string, employee_state, Employee_state);
	//到单位时间5
	CC_SYNTHESIZE(string, Time_unit, Time_Unit);
	//合同编号6
	CC_SYNTHESIZE(string, contract_id, Contract_id);
	//合同单位7
	CC_SYNTHESIZE(string, Contract_unit, Contract_Unit);
	//合同类别8
	CC_SYNTHESIZE(string, Class_contract, Class_Contract);
	//9
	CC_SYNTHESIZE(string, contract_type, contract_Type);
	//10
	CC_SYNTHESIZE(string, start_date, Start_date);
	// 11
	CC_SYNTHESIZE(string, stop_date, Stop_date);
	// 12
	CC_SYNTHESIZE(string, Operation_column, Operation_Column);
public:
	contractManagerDO() {
	}
};

#endif // !_CONTRACTMANAGERDO_H_
