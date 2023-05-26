#pragma once
#ifndef _BLACKLIST_DO_
#define _BLACKLIST_DO_
#include "../DoInclude.h"


class BlacklistDO
{
	//员工编号
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//员工姓名
	CC_SYNTHESIZE(string, ygxm, Ygxm);
	//证件编号
	CC_SYNTHESIZE(string, zjbh, Zjbh);
	//组织
	CC_SYNTHESIZE(string, zz, Zz);
	//员工状态
	CC_SYNTHESIZE(string, ygzt, Ygzt);
	//是否列入黑名单
	CC_SYNTHESIZE(string, lrhmd, Lrhmd);
	//黑名单原因
	CC_SYNTHESIZE(string, hmdyy, Hmdyy);
public:
	BlacklistDO() {
		ygbh = "";
		ygxm = "";
		zjbh = "";
		zz = "";
		ygzt = "";
		lrhmd = "";
		hmdyy = "";
	}
};

#endif