#pragma once
#ifndef _SECONDED_PERSONNEL_DO_
#define _SECONDED_PERSONNEL_DO_
#include "../DoInclude.h"

/*
 借调员工DO--（人员花名册）--pine
 (对应数据库表t_pcmydjdmx：异动借调明细 与 t_pcmydmx：异动明细)
 */
class SecondedPersonnelDO
{
	// 借调人员标识
	CC_SYNTHESIZE(string, PIMDISTIRBUTIONID, PIMDISTIRBUTIONID);
	// 编号和姓名 模糊查询
	CC_SYNTHESIZE(string, idAndName, idAndName);
	// 员工编号
	CC_SYNTHESIZE(string, ygbh, ygbh);
	// 员工姓名
	CC_SYNTHESIZE(string, pimPersonName, pimPersonName);
	// 原组织
	CC_SYNTHESIZE(string, zz, zz);
	// 原部门
	CC_SYNTHESIZE(string, bm, bm);
	// 原职务
	CC_SYNTHESIZE(string, yzw, yzw);
	// 原岗位
	CC_SYNTHESIZE(string, ygw, ygw);
	// 新组织
	CC_SYNTHESIZE(string, ormName, ormName);
	// 新部门
	CC_SYNTHESIZE(string, ormOrgSectorName, ormOrgSectorName);
	// 新职务
	CC_SYNTHESIZE(string, ormDutyName, ormDutyName);
	// 新岗位
	CC_SYNTHESIZE(string, ormPostName, ormPostName);
	// 借调状态（异动借调明细标识）
	CC_SYNTHESIZE(string, pcmydjdmxId, pcmydjdmxId);
	//借调开始时间
	CC_SYNTHESIZE(string, jdksrq, jdksrq);
	//借调结束时间
	CC_SYNTHESIZE(string, jdjsrq, jdjsrq);

public:
	SecondedPersonnelDO() {
		PIMDISTIRBUTIONID = "";
		idAndName = "";
		ygbh = "";
		pimPersonName = "";
		zz = "";
		bm = "";
		yzw = "";
		ygw = "";
		ormName = "";
		ormOrgSectorName = "";
		ormDutyName = "";
		ormPostName = "";
		pcmydjdmxId = "";
		jdksrq = "";
		jdjsrq = "";
	}
};

#endif // !_SAMPLE_DO_
