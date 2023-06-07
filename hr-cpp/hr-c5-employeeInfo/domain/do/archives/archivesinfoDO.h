#pragma once
#ifndef _ARCHIVES_INFO_DO_
#define _ARCHIVES_INFO_DO_
#include "../DoInclude.h"

/**
 * 指定档案详情类
 */

class archivesinfoDO
{
	// 档案信息标识
	CC_SYNTHESIZE(string, pimarchivesid, PIMARCHIVESID);
	// 档案编号
	CC_SYNTHESIZE(string, dabh, DABH);
	// 管理单位
	CC_SYNTHESIZE(string, orgname, ORGNAME);
	// 是否新建档
	CC_SYNTHESIZE(string, sfxjd, SFXJD);
	// 档案室
	CC_SYNTHESIZE(string, archivescentername, ARCHIVESCENTERNAME);
	// 档案保管地
	CC_SYNTHESIZE(string, dabgd, DABGD);
	// 员工姓名
	CC_SYNTHESIZE(string, pimpersonname, PIMPERSONNAME);
	// 员工编号
	CC_SYNTHESIZE(string, ygbh, YGBH);
	// 所属单位
	CC_SYNTHESIZE(string, ormorgname, ORMORGNAME);
	// 档案学历
	CC_SYNTHESIZE(string, education, EDUCATION);
	// 档案出生日期
	CC_SYNTHESIZE(string, dateofbirth, DATEOFBIRTH);
	// 档案入党时间
	CC_SYNTHESIZE(string, joinpartydate, JOINPARTYDATE);
	// 档案参加工作时间
	CC_SYNTHESIZE(string, startworkdatae, STARTWORKDATAE);
	// 档案状态
	CC_SYNTHESIZE(string, dazt, DAZT);
	// 备注
	CC_SYNTHESIZE(string, bz, BZ);
	// 附件
	CC_SYNTHESIZE(string, fj, FJ);
public:
	archivesinfoDO() {
		pimarchivesid = "";
		dabh = "";
		orgname = "";
		sfxjd = "";
		archivescentername = "";
		dabgd = "";
		pimpersonname = "";
		ygbh = "";
		ormorgname = "";
		education = "";
		dateofbirth = "";
		joinpartydate = "";
		startworkdatae = "";
		dazt = "";
		bz = "";
		fj = "";
	}
};

#endif