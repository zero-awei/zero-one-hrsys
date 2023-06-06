#pragma once
#ifndef _J_PATENTINFO_DO_
#define _J_PATENTINFO_DO_
#include "../DoInclude.h"

/**
 * 专利数据库实体类
 */
class J_PatentinfoDO
{
    //ZLH:专利号
    CC_SYNTHESIZE(string, zlh, ZLH);
    //UPDATEDATE : 更新时间
    CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
    //PIMPATENTID : 专利信息编码
    CC_SYNTHESIZE(string, pimpatentid, PIMPATENTID);
    //ZLHQSJ : 专利获取时间
    CC_SYNTHESIZE(string, zlhqsj, ZLHQSJ);
	//ENABLE : 
	CC_SYNTHESIZE(string, enable, ENABLE);
    //PIMPATENTNAME : 专利名称
    CC_SYNTHESIZE(string, pimpatentname, PIMPATENTNAME);
    //UPDATEMAN : 更新人
    CC_SYNTHESIZE(string, updateman, UPDATEMAN);
    //CREATEMAN : 建立人
    CC_SYNTHESIZE(string, createman, CREATEMAN);
    //CREATEDATE : 建立时间
    CC_SYNTHESIZE(string, createdate, CREATEDATE);
    //ZLPZGB : 专利批准国别
    CC_SYNTHESIZE(string, zlpzgb, ZLPZGB);
    //PIMPERSONID : 人员信息标识
    CC_SYNTHESIZE(string, pimpersonid, PIMPERSONID);
    //JLSS : 记录所属
    CC_SYNTHESIZE(string, jlss, JLSS);
    //JLSPZT : 审批状态
    CC_SYNTHESIZE(string, jlspzt, JLSPZT);
    //JLGLBH : 记录管理编号
    CC_SYNTHESIZE(string, jlglbh, JLGLBH);
    //JLCZZ : 记录操作者
    CC_SYNTHESIZE(string, jlczz, JLCZZ);
    //ENCLOLURE : 附件
    CC_SYNTHESIZE(string, enclolure, ENCLOLURE);
    //REASON : 拒绝原因
    CC_SYNTHESIZE(string, reason, REASON);




	//ORGID : 组织标识1
	CC_SYNTHESIZE(string, orgid, ORGID);
	//ORGSECTORID : 部门标识1
	CC_SYNTHESIZE(string, orgsectorid, ORGSECTORID);
	//ORMORGID : 组织标识2
	CC_SYNTHESIZE(string, ormorgid, ORMORGID);
	//ORMORGSECTORID : 部门标识2
	CC_SYNTHESIZE(string, ormorgsectorid, ORMORGSECTORID);
	//PIMPERSONNAME : 员工姓名
	CC_SYNTHESIZE(string, pimpersonname, PIMPERSONNAME);
	//YGBH : 员工编号
	CC_SYNTHESIZE(string, ygbh, YGBH);

public:
    J_PatentinfoDO() {

        zlh = "";
        updatedate = "";
        pimpatentid = "";
        zlhqsj = "";
		enable = "";
        pimpatentname = "";
        updateman = "";
        createman = "";
        createdate = "";
        zlpzgb = "";
        pimpersonid = "";
        jlss = "";
        jlspzt = "";
        jlglbh = "";
        jlczz = "";
        enclolure = "";
        reason = "";

		orgid = "";
		orgsectorid = "";
		ormorgid = "";
		ormorgsectorid = "";
		pimpersonname = "";
		ygbh = "";
    }
};

#endif // !_SAMPLE_DO_


