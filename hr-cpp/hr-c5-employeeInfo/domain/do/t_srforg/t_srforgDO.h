#pragma once
#pragma once
#ifndef _T_SRGORG_DO_
#define _T_SRGORG_DO_
#include "../DoInclude.h"

class t_srforgDO
{
	//管理单位中文编码 位于数据表t_srforg
	CC_SYNTHESIZE(string, orgname, Orgname);
public:
	t_srforgDO() {
		orgname = "";
	}
};

#endif // !_T_SRGORG_DO_