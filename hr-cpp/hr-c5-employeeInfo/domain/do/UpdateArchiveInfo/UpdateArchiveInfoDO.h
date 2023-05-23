#pragma once
#pragma once
#ifndef _UPDATE_ARCHIVE_INFO_DO_
#define _UPDATE_ARCHIVE_INFO_DO_
#include "../DoInclude.h"

/**
 * 更新档案实体类
 */
class NotEmployeeInArchiveDO
{
	// 档案编号
	CC_SYNTHESIZE(string, dabh, Dabh);
	// 管理单位
	CC_SYNTHESIZE(string, gldw, Gldw);
	// 是否新建档
	CC_SYNTHESIZE(string, sfxjd, sfxjd);
	// 保管地
	CC_SYNTHESIZE(string, bgd, Bgd);
	// 档案室
	CC_SYNTHESIZE(string, archivescentername, Archivescentername);
	//员工编号
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//员工姓名
	CC_SYNTHESIZE(string, pimpersonname, Pimpersonname);
	//所属单位
	CC_SYNTHESIZE(string, ormorgname, Ormorgname);
	//档案学历
	CC_SYNTHESIZE(string, education, Education);
	//档案出生日期
	CC_SYNTHESIZE(string, dateofbirth, dateofbirth);
	// 档案入党时间
	CC_SYNTHESIZE(string, joinpartydate, Joinpartydate);
	// 档案参加工作时间
	CC_SYNTHESIZE(string, startworkdate, startworkdate);
	// 档案状态
	CC_SYNTHESIZE(string, dastate, dastate);
	//备注
	CC_SYNTHESIZE(string, bz, bz);
	//附件
	CC_SYNTHESIZE(string, fj, fj);
public:
	NotEmployeeInArchiveDO() {
		dabh = "";
		gldw = "";
		sfxjd = "";
		bgd = "";
		archivescentername = "";
		ygbh = "";
		pimpersonname = "";
		ormorgname = "";
		education = "";
		dateofbirth = "";
		joinpartydate = "";
		startworkdate = "";
		dastate = "";
		bz = "";
		fj = "";
	}
};

#endif // !_UPDATE_ARCHIVE_INFO_DO_