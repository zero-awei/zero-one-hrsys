#pragma once
#ifndef _Gosh_DO_
#define _Gosh_DO_
#include "../DoInclude.h"
/**
 * 示例数据库实体类
 */
class ContractDO
{
	//1员工编号
	CC_SYNTHESIZE(string, personid, Personid);
	// 2合同编号
	CC_SYNTHESIZE(string, id, Id);
	// 3员工姓名
	CC_SYNTHESIZE(string, name, Name);
	//4合同类别
	CC_SYNTHESIZE(string, type, Type);
	//5合同类型
	CC_SYNTHESIZE(string, variety, Variety);
	//6起始日期
	CC_SYNTHESIZE(string, date, Date);
	//7合同状态
	CC_SYNTHESIZE(string, condition, Condition);
	//8合同签订单位
	CC_SYNTHESIZE(string, department_c, Department_c);
	//9试用到期时间
	CC_SYNTHESIZE(string, date_end, Date_end);
	//10员工所属单位
	CC_SYNTHESIZE(string, person_department, Person_department);
	//11员工状态
	CC_SYNTHESIZE(string, person_condition, Person_condition);
	//12到本单位时间
	CC_SYNTHESIZE(string, date_arrive, Date_arrive);
	//13结束日期
	CC_SYNTHESIZE(string, date_over, Date_over);
	//14合同剩余天数
	CC_SYNTHESIZE(string, rest, Rest);
	//15合同管理单位
	CC_SYNTHESIZE(string, department_m, Department_m);
	//16备注
	CC_SYNTHESIZE(string, tip, Tip);
	//17是否展示列
	CC_SYNTHESIZE(string, row_show, Row_show);
public:
	ContractDO() {
		personid = "";
		id = "";
		name = "";
		type = "";
		variety = "";
		date= "";
		condition = "";
		department_c = "";
		date_end = "";
		person_department = "";
		person_condition = "";
		date_arrive = "";
		date_over = "";
		rest = "";
		department_m = "";
		tip = "";
		row_show = "11111111111111";
	}
};

#endif 
