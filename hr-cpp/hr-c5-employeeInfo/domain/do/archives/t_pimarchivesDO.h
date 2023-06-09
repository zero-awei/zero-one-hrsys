#pragma once
#ifndef _ARCHIVES_DO_
#define _ARCHIVES_DO_
#include "../DoInclude.h"

/**
* 档案信息实体类
*/
class t_pimarchivesDO
{
	//档案信息标识
	CC_SYNTHESIZE(string, pimArchivesId, PimArchivesId);
	// 档案编号
	CC_SYNTHESIZE(string, dabh, Dabh);
	// 管理单位
	CC_SYNTHESIZE(string, orgName, OrgName);
	// 档案保管地
	CC_SYNTHESIZE(string, dabgd, Dabgd);
	// 档案室
	CC_SYNTHESIZE(string, archivesCenterName, ArchivesCenterName);
	// 档案状态
	CC_SYNTHESIZE(string, dazt, Dazt);
	// 员工编号
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	// 员工姓名
	CC_SYNTHESIZE(string, pimPersonName, PimPersonName);
	// 员工状态
	CC_SYNTHESIZE(string, ygzt, Ygzt);
	// 所属单位
	CC_SYNTHESIZE(string, ormOrgName, OrmOrgName);
	// 档案借阅状态
	CC_SYNTHESIZE(string, zt, Zt);
	//-------------详细查询额外使用的字段----------------
	// 档案学历
	CC_SYNTHESIZE(string, education, Education);
	// 档案出生时间
	CC_SYNTHESIZE(string, dateOfBirth, DateOfBirth);
	// 档案入党时间
	CC_SYNTHESIZE(string, joinPartyDate, JoinPartyDate);
	// 添加工作时间
	CC_SYNTHESIZE(string, startWorkDatae, StartWorkDatae);
	//-------------外键的唯一标识----------------
	// t_pimperson
	CC_SYNTHESIZE(string, pimPersonId, PimPersonId);
	// t_srforg
	CC_SYNTHESIZE(string, orMorGId3, OrMorGId3);
	// t_archivescenter
	CC_SYNTHESIZE(string, archivesCenterId, ArchivesCenterId);
public:
	t_pimarchivesDO() {
		pimArchivesId = "";
		dabh = "";
		orgName = "";
		dabgd = "";
		archivesCenterName = "";
		dazt = "";
		ygbh = "";
		pimPersonName = "";
		ygzt = "";
		ormOrgName = "";
		zt = "";
		education = "";
		dateOfBirth = "";
		joinPartyDate = "";
		startWorkDatae = "";
		pimPersonId = "";
		orMorGId3 = "";
		archivesCenterId = "";
	}
};
#endif // !_ARCHIVES_DO_
