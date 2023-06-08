#ifndef _CONTRACTINFODO_
#define _CONTRACTINFODO_
#include "../DoInclude.h"
class ContractInfoDO
{
	// 1员工编号t_pimperson.YGBH
	CC_SYNTHESIZE(string, id, Id);
	// 2员工姓名t_pimperson.PIMPERSONNAME
	CC_SYNTHESIZE(string, name, Name);
	//3合同类别t_pimcontract.HTLX
	CC_SYNTHESIZE(string, type, Type);
	//4合同类型t_pimcontract.CONTRACTTYPE
	CC_SYNTHESIZE(string, variety, Variety);
	//5起始日期t_pimcontract.QSRQ
	CC_SYNTHESIZE(string, date, Date);
	//6合同状态t_pimcontract.HTZT
	CC_SYNTHESIZE(string, condition, Condition);
	//7员工所属单位t_pimcontract.ORMORGNAME
	CC_SYNTHESIZE(string, department_m, Department_m);
	//8合同签订单位t_pimcontract.LEGALORG
	CC_SYNTHESIZE(string, department_c, Department_c);
	//9试用到期时间t_pimcontract.SYDQSJ
	CC_SYNTHESIZE(string, try_end, Try_end);
	//10备注t_pimcontract.DEMO
	CC_SYNTHESIZE(string, tip, Tip);
	//11员工信息标识t_pimcontract.PIMCONTRACTID (key)
	CC_SYNTHESIZE(string, infoid, Infoid);
	//12合同结束日期t_pimcontract.JSRQ
	CC_SYNTHESIZE(string, date_end, Date_end);
	//13合同编号t_pimcontract.HTBH
	CC_SYNTHESIZE(string, contract_num, Contract_num);
	//14员工状态t_pimperson.YGZT
	CC_SYNTHESIZE(string, emp_condition, Emp_condition);
public:
	ContractInfoDO() {
		id = "";
		name = "";
		type = "";
		variety = "";
		date = "";
		condition = "";
		department_m = "";
		department_c = "";
		try_end = "";
		tip = "";
		infoid = "";
		date_end = "";
		contract_num = "";
		emp_condition = "";
	}
};





#endif