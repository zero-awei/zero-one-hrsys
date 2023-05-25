#pragma once
#ifndef _RRAINEE_DO_
#define _RRAINEE_DO_
#include "../DoInclude.h"

/**
 *  基础管理 —— 人员花名册 —— 见习员工实体类  ——Cpt
 */
class ExportEmployeeDO {
	// 员工编号
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// 员工姓名            
	CC_SYNTHESIZE(string, pcmjxszzkhjgjlname, pcmjxszzkhjgjlname);
	// 组织
	CC_SYNTHESIZE(string, zz, zz);
	// 部门
	CC_SYNTHESIZE(string, bm, bm);
	// 职务
	CC_SYNTHESIZE(string, zw, zw);
	// 岗位
	CC_SYNTHESIZE(string, gw, gw);
	// 见习期限（月）
	CC_SYNTHESIZE(string, duration, duration);  
	// 到本单位时间
	CC_SYNTHESIZE(string, ksrq, ksrq); 
	// 见习到期时间
	CC_SYNTHESIZE(string, jsrq, jsrq);  
public:
	ExportEmployeeDO() {
	
	}
};

#endif // !_RRAINEE_DO_
