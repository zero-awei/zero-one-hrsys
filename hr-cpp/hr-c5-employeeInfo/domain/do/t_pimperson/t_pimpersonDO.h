#pragma once
#pragma once
#ifndef _T_PIMPERSON_DO_
#define _T_PIMPERSON_DO_
#include "../DoInclude.h"

/**
 * 更新档案实体类
 */
class t_pimpersonDO
{
	//员工编号 位于数据表t_pimperson
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//员工姓名 位于数据表t_pimperson
	CC_SYNTHESIZE(string, pimpersonname, Pimpersonname);
	//员工状态 位于数据表t_pimperson
	CC_SYNTHESIZE(string, ygzt, Ygzt);
public:
	t_pimpersonDO() {
		ygbh = "";
		pimpersonname = "";
		ygzt = "";
	}
};

#endif // !_T_PIMPERSON_DO_