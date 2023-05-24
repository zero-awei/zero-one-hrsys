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
    CC_SYNTHESIZE(string, ZLH, ZLH);
    //UPDATEDATE : 更新时间
    CC_SYNTHESIZE(string, UPDATEDATE, UPDATEDATE);
    //PIMPATENTID : 专利信息编码
    CC_SYNTHESIZE(string, PIMPATENTID, PIMPATENTID);
    //ZLHQSJ : 专利获取时间
    CC_SYNTHESIZE(string, ZLHQSJ, ZLHQSJ);
    //PIMPATENTNAME : 专利名称
    CC_SYNTHESIZE(string, PIMPATENTNAME, PIMPATENTNAME);
    //UPDATEMAN : 更新人
    CC_SYNTHESIZE(string, UPDATEMAN, UPDATEMAN);
    //CREATEMAN : 建立人
    CC_SYNTHESIZE(string, CREATEMAN, CREATEMAN);
    //CREATEDATE : 建立时间
    CC_SYNTHESIZE(string, CREATEDATE, CREATEDATE);
    //ZLPZGB : 专利批准国别
    CC_SYNTHESIZE(string, ZLPZGB, ZLPZGB);
    //PIMPERSONID : 人员信息标识
    CC_SYNTHESIZE(string, PIMPERSONID, PIMPERSONID);
    //JLSS : 记录所属
    CC_SYNTHESIZE(string, JLSS, JLSS);
    //JLSPZT : 审批状态
    CC_SYNTHESIZE(string, JLSPZT, JLSPZT);
    //JLGLBH : 记录管理编号
    CC_SYNTHESIZE(string, JLGLBH, JLGLBH);
    //JLCZZ : 记录操作者
    CC_SYNTHESIZE(string, JLCZZ, JLCZZ);
    //ENCLOLURE : 附件
    CC_SYNTHESIZE(string, ENCLOLURE, ENCLOLURE);
    //REASON : 拒绝原因
    CC_SYNTHESIZE(string, REASON, REASON);
public:
    PatentinfoDO() {

        ZLH = "";
        UPDATEDATE = "";
        PIMPATENTID = "";
        ZLHQSJ = "";
        PIMPATENTNAME = "";
        UPDATEMAN = "";
        CREATEMAN = "";
        CREATEDATE = "";
        ZLPZGB = "";
        PIMPERSONID = "";
        JLSS = "";
        JLSPZT = "";
        JLGLBH = "";
        JLCZZ = "";
        ENCLOLURE = "";
        REASON = "";
    }
};

#endif // !_SAMPLE_DO_


