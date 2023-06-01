#pragma once
#ifndef _PAPERINFO_DO_
#define _PAPERINFO_DO_
#include "../DoInclude.h"

/**
 * 专利数据库实体类
 */
class PaperinfoDO
{
    //GRZLWZZZDPM:个人在论文著作中的排名
    CC_SYNTHESIZE(string, grzlwzzzdpm, GRZLWZZZDPM);
	//UPDATEMAN:更新人
	CC_SYNTHESIZE(string, updateman, UPDATEMAN);
	//PIMPAPERID:论文信息标识
	CC_SYNTHESIZE(string, pimpaperid, PIMPAPERID);
	//CREATEDATE:建立时间
	CC_SYNTHESIZE(string, createdate, CREATEDATE);
	//UPDATEDATE:更新时间
	CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
	//CREATEMAN:建立人
	CC_SYNTHESIZE(string, createman, CREATEMAN);
	//FBSJ:发表时间
	CC_SYNTHESIZE(string, fbsj, FBSJ);
	//PIMPAPERNAME:论文名称
	CC_SYNTHESIZE(string, pimpapername, PIMPAPERNAME);
	//CBSHKWMC:出版社或刊物名称
	CC_SYNTHESIZE(string, cbshkwmc, CBSHKWMC);
	//PIMPERSONID:人员信息标识
	CC_SYNTHESIZE(string, pimpersonid, PIMPERSONID);
	//FJ:附件
	CC_SYNTHESIZE(string, fj, FJ);
	//JLSPZT:审批状态
	CC_SYNTHESIZE(string, jlspzt, JLSPZT);
	//JLGLBH:记录管理编号
	CC_SYNTHESIZE(string, jlglbh, JLGLBH);
	//JLCZZ:记录操作者
	CC_SYNTHESIZE(string, jlczz, JLCZZ);
	//JLSS:记录所属
	CC_SYNTHESIZE(string, jlss, JLSS);
	//CBS:出版社
	CC_SYNTHESIZE(string, cbs, CBS);
	//KWMC:刊物名称
	CC_SYNTHESIZE(string, kwmc, KWMC);
	//KWQS:刊物期数
	CC_SYNTHESIZE(string, kwqs, KWQS);
	//REASON:拒绝原因
	CC_SYNTHESIZE(string, reason, REASON);
public:
    PaperinfoDO() {

		grzlwzzzdpm = "";
		updateman = "";
		pimpaperid = "";
		createdate = "";
		updatedate = "";
		createman = "";
		fbsj = "";
		pimpapername = "";
		cbshkwmc = "";
		pimpersonid = "";
		fj = "";
		jlspzt = "";
		jlglbh = "";
		jlczz = "";
		jlss = "";
		cbs = "";
		kwmc = "";
		kwqs = "";
		reason = "";
 
    }
};

#endif // !_SAMPLE_DO_


