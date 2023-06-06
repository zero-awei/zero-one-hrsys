#pragma once
#ifndef _PATENTINFO_DO_
#define _PATENTINFO_DO_
#include "../DoInclude.h"

/**
 * 专利数据库实体类
 */
class PatentinfoDO
{
    //ZLH:专利号
    CC_SYNTHESIZE(string, zlh, ZLH);
    //UPDATEDATE : 更新时间
    CC_SYNTHESIZE(string, updatedate, UPDATEDATE);
    //PIMPATENTID : 专利信息编码
    CC_SYNTHESIZE(string, pimpatentid, PIMPATENTID);
    //ZLHQSJ : 专利获取时间
    CC_SYNTHESIZE(string, zlhqsj, ZLHQSJ);
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
public:
    PatentinfoDO() {

        zlh = "";
        updatedate = "";
        pimpatentid = "";
        zlhqsj = "";
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
    }
};

#endif // !_SAMPLE_DO_

