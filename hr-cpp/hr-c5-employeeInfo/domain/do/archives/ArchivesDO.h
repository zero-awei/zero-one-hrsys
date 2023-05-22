#pragma once
#ifndef _ARCHIVES_DO_
#define _ARCHIVES_DO_
#include "../DoInclude.h"

/**
* 档案信息实体类
*/
class ArchivesDO
{
	// 档案编号
	CC_SYNTHESIZE(string, archivesNo, ArchivesNo);
	// 管理单位
	CC_SYNTHESIZE(string, managementUnits, ManagementUnits);
	// 档案保管地
	CC_SYNTHESIZE(string, DABGD);
	// 档案室
	CC_SYNTHESIZE(string, archivesCenterName, ArchivesCenterName);
	// 员工编号
	CC_SYNTHESIZE(string, YGBH);
	// 员工姓名
	CC_SYNTHESIZE(string, pimPersonName, PimPersonName);
	// 员工状态
	CC_SYNTHESIZE(string, ygzt);
	// 所属单位
	CC_SYNTHESIZE(string, ORMORGName);
	// 档案状态
	CC_SYNTHESIZE(string, DAZT);
public:
	ArchivesDO() {
		archivesNo = "";
		managementUnits = "";
		DABGD = "";
		archivesCenterName = "";
		YGBH = "";
		pimPersonName = "";
		ygzt = "";
		ORMORGName = "";
		DAZT = "";
	}
};
#endif // !_ARCHIVES_DO_
