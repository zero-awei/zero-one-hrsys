#pragma once
#ifndef _NOT_EMPLOYEE_IN_ARCHIVE_DO_
#define _NOT_EMPLOYEE_IN_ARCHIVE_DO_
#include "../DoInclude.h"

/**
 * 非员工在档实体类
 */
class NotEmployeeInArchiveDO
{
	// 档案编号
	CC_SYNTHESIZE(string, dabh, Dabh);
	// 管理单位
	CC_SYNTHESIZE(string, gldw, Gldw);
	// 保管地
	CC_SYNTHESIZE(string, bgd, Bgd);
	// 档案室
	CC_SYNTHESIZE(string, archivescentername, Archivescentername);
	//档案状态
	CC_SYNTHESIZE(string, dazt, Dazt);
	//员工编号
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//员工姓名
	CC_SYNTHESIZE(string, pimpersonname, Pimpersonname);
	//所属单位
	CC_SYNTHESIZE(string, ormorgname, Ormorgname);
	//员工状态
	CC_SYNTHESIZE(string, ygzt, Ygzt);

public:
	NotEmployeeInArchiveDO() {
		dabh = "";
		gldw = "";
		bgd = "";
		archivescentername = "";
		dazt = "";
		pimpersonname = "";
		ormorgname = "";
		ygzt = "";
	}
};

#endif // !_NOT_EMPLOYEE_IN_ARCHIVE_DO_