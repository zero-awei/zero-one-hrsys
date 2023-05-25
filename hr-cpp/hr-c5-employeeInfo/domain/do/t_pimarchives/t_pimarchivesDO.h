#pragma once
#ifndef _T_PIMARCHIVES_DO_
#define _T_PIMARCHIVES_DO_
#include "../DoInclude.h"

/**
 * 非员工在档 档案管理实体类
 */
class t_pimarchivesDO
{
	// 档案编号
	CC_SYNTHESIZE(string, dabh, Dabh);
	// 管理单位id
	CC_SYNTHESIZE(string, ormorgid3, Ormorgid3);
	//管理单位中文编码 位于数据表t_srforg
	CC_SYNTHESIZE(string, orgname, Orgname);
	// 档案保管地
	CC_SYNTHESIZE(string, dabgd, Dabgd);
	// 档案室id
	CC_SYNTHESIZE(string, archivescenterid, Archivescenterid);
	//档案室中文编码 位于数据表t_archivescenter
	CC_SYNTHESIZE(string, archivescentername, Archivescentername);
	//档案状态
	CC_SYNTHESIZE(string, dazt, Dazt);
	//员工id
	CC_SYNTHESIZE(string, pimpersonid, Pimpersonid);
	//员工编号 位于数据表t_pimperson
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//员工姓名 位于数据表t_pimperson
	CC_SYNTHESIZE(string, pimpersonname, Pimpersonname);
	//所属单位
	CC_SYNTHESIZE(string, ormorgname, Ormorgname);
	//员工状态 位于数据表t_pimperson
	CC_SYNTHESIZE(string, ygzt, Ygzt);
	//操作列
	CC_SYNTHESIZE(string, operations, Operations);


	// 是否新建档
	CC_SYNTHESIZE(string, sfxjd, Sfxjd);
	//备注
	CC_SYNTHESIZE(string, bz, Bz);
	//档案学历
	CC_SYNTHESIZE(string, education, Education);
	//档案出生日期
	CC_SYNTHESIZE(string, dateofbirth, Dateofbirth);
	//档案入党时间
	CC_SYNTHESIZE(string, joinpartydate, Joinpartydate);
	//档案参加工作时间
	CC_SYNTHESIZE(string, startworkdate, Startworkdate);
	//附件
	CC_SYNTHESIZE(string, fj, Fj);
public:
	t_pimarchivesDO() {
		dabh = "";
		ormorgid3 = "";
		orgname = "";
		dabgd = "";
		archivescenterid = "";
		archivescentername = "";
		dazt = "";
		pimpersonid = "";
		ygbh = "";
		pimpersonname = "";
		ormorgname = "";
		ygzt = "";
		operations = "";
		sfxjd = "";
		bz = "";
		education = "";
		dateofbirth = "";
		joinpartydate = "";
		startworkdate = "";
		fj = "";
	}
};

#endif // !_T_PIMARCHIVES_DO_