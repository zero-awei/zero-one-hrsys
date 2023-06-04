#pragma once
#ifndef _RRAINEE_DO_
#define _RRAINEE_DO_
#include "../DoInclude.h"
/**
 *  基础管理 —— 人员花名册 —— 见习员工实体类  ——Cpt
 */

class RraineeDO {
	// 员工编号
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	// 员工姓名            
	CC_SYNTHESIZE(string, pcmjxszzkhjgjlname, Pcmjxszzkhjgjlname);
	// 组织
	CC_SYNTHESIZE(string, zz, Zz);
	// 部门
	CC_SYNTHESIZE(string, bm, Bm);
	// 职务
	CC_SYNTHESIZE(string, zw, Zw);
	// 岗位
	CC_SYNTHESIZE(string, gw, Gw);
	// 见习期限（月）
	CC_SYNTHESIZE(string, duration, Duration);  
	// 到本单位时间
	CC_SYNTHESIZE(string, ksrq, Ksrq); 
	// 见习到期时间
	CC_SYNTHESIZE(string, jsrq, Jsrq);  
public:
	RraineeDO() {
	
	}
};

#endif // !_RRAINEE_DO_
