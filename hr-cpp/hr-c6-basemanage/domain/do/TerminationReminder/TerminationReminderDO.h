#pragma once
#include "../DoInclude.h"
class TerminationReminderDO
{
	// 员工编号
	CC_SYNTHESIZE(string, employee_id, EmployeeId);
	// 员工姓名
	CC_SYNTHESIZE(string, employee_name, EmployeeName);
	// 员工所属单位
	CC_SYNTHESIZE(string, employee_part, EmployeePart);
	// 员工状态
	CC_SYNTHESIZE(string, employee_status, EmployeeStatus);
	//到本单位时间
	CC_SYNTHESIZE(string, arrived_time,ArrivedTime );
	//合同编号						  
	CC_SYNTHESIZE(string, contract_id, ContractId);
	//合同签订单位						  
	CC_SYNTHESIZE(string, contract_sign_part,ContractSignPart );
	//合同类别					  
	CC_SYNTHESIZE(string, contract_lb,ContractLB );
	//合同类型						  
	CC_SYNTHESIZE(string, contract_lx,ContractLX );
	//起始日期					  
	CC_SYNTHESIZE(string, begin_time, BeginTime);
	//结束日期					  
	CC_SYNTHESIZE(string, deadline, Deadline);
public:
	TerminationReminderDO() {
	}
};
