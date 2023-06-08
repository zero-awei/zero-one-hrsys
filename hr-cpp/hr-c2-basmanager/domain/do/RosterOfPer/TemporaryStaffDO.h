#pragma once
#ifndef _TEMPORARYSTAFF_DO_
#define _TEMPORARYSTAFF_DO_
#include "../DoInclude.h"
/**
 * 挂职人员信息查询功能数据库实体，搜索框使用--(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
 */

class TemporaryStaffDO {
	//员工编号
	CC_SYNTHESIZE(string, ygbh, ygbh);
	//员工姓名
	CC_SYNTHESIZE(string, pimPersonName, pimPersonName);
	//员工状态
	CC_SYNTHESIZE(string, ygzt, ygzt);
	//挂职状态
	CC_SYNTHESIZE(string, gzzt, gzzt);
	//挂职组织
	CC_SYNTHESIZE(string, gzzz, gzzz);
	//挂职部门
	CC_SYNTHESIZE(string, gzbm, gzbm);
	//挂职开始时间
	CC_SYNTHESIZE(string, gzkssj, gzkssj);
	//挂职结束时间
	CC_SYNTHESIZE(string, gzjssj, gzjssj);
	//人员信息唯一标识
	CC_SYNTHESIZE(string, pimpersonId, pimpersonId);
public:
	TemporaryStaffDO() {
		ygbh = "0";
		pimPersonName = "";
		ygzt = "在职";
		gzzt = "挂职进";
		gzzz = "";
		gzbm = "";
		gzkssj = "";
		gzjssj = "";
		pimpersonId = "";
	}
};
#endif // !_TEMPORARYSTAFF_DO_
