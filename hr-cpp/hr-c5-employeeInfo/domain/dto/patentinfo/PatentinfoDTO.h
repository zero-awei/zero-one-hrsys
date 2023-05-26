#pragma once


#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 专利信息传输对象
 */
class PatentinfoDTO : public oatpp::DTO
{

public:
    PatentinfoDTO() {};
    PatentinfoDTO(String zlh, String pimpatentname) :zlh(zlh), pimpatentname(pimpatentname) {};

    DTO_INIT(PatentinfoDTO, DTO);

    //ZLH:专利号
    DTO_FIELD(String, zlh);
    DTO_FIELD_INFO(zlh) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLH");
    }

    //UPDATEDATE : 更新时间
    DTO_FIELD(String, updatedate);
    DTO_FIELD_INFO(updatedate) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.UPDATEDATE");
    }

    //PIMPATENTID : 专利信息编码
    DTO_FIELD(String, pimpatentid);
    DTO_FIELD_INFO(pimpatentid) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTID");
    }

    //ZLHQSJ : 专利获取时间
    DTO_FIELD(String, zlhqsj);
    DTO_FIELD_INFO(zlhqsj) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLHQSJ");
    }
    
    //PIMPATENTNAME : 专利名称
    DTO_FIELD(String, pimpatentname);
    DTO_FIELD_INFO(pimpatentname) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTNAME");
    }

    //UPDATEMAN : 更新人
    DTO_FIELD(String, updateman);
    DTO_FIELD_INFO(updateman) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.UPDATEMAN");
    }
    
    //CREATEMAN : 建立人
    DTO_FIELD(String, createman);
    DTO_FIELD_INFO(createman) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.CREATEMAN");
    }
    
    //CREATEDATE : 建立时间
    DTO_FIELD(String, createdate);
    DTO_FIELD_INFO(createdate) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.CREATEDATE");
    }
    
    //ZLPZGB : 专利批准国别
    DTO_FIELD(String, zlpzgb);
    DTO_FIELD_INFO(zlpzgb) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLPZGB");
    }
    
    //PIMPERSONID : 人员信息标识
    DTO_FIELD(String, pimpersonid);
    DTO_FIELD_INFO(pimpersonid) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPERSONID");
    }
    
    //JLSS : 记录所属
    DTO_FIELD(String, jlss);
    DTO_FIELD_INFO(jlss) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.JLSS");
    }
    
    //JLSPZT : 审批状态
    DTO_FIELD(String, jlspzt);
    DTO_FIELD_INFO(jlspzt) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.JLSPZT");
    }
    
    //JLGLBH : 记录管理编号
    DTO_FIELD(String, jlglbh);
    DTO_FIELD_INFO(jlglbh) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.JLGLBH");
    }
    
    //JLCZZ : 记录操作者
    DTO_FIELD(String, jlczz);
    DTO_FIELD_INFO(jlczz) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.JLCZZ");
    }
    
    //ENCLOLURE : 附件
    DTO_FIELD(String, enclolure);
    DTO_FIELD_INFO(enclolure) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ENCLOLURE");
    }
    
    //REASON : 拒绝原因
    DTO_FIELD(String, reason);
    DTO_FIELD_INFO(reason) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.REASON");
    }

};

/**
 * 分页传输对象
 */
class PatentinfoPageDTO : public PageDTO<PatentinfoDTO::Wrapper>
{
    DTO_INIT(PatentinfoPageDTO, PageDTO<PatentinfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
