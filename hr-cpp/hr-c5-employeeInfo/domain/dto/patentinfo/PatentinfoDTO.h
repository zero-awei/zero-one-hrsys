#pragma once


#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ר����Ϣ�������
 */
class PatentinfoDTO : public oatpp::DTO
{

public:
    PatentinfoDTO() {};
    PatentinfoDTO(String zlh, String pimpatentname) :zlh(zlh), pimpatentname(pimpatentname) {};

    DTO_INIT(PatentinfoDTO, DTO);

    //ZLH:ר����
    DTO_FIELD(String, zlh);
    DTO_FIELD_INFO(zlh) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlh");
    }

    //UPDATEDATE : ����ʱ��
    DTO_FIELD(String, updatedate);
    DTO_FIELD_INFO(updatedate) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updatedate");
    }

    //PIMPATENTID : ר����Ϣ����
    DTO_FIELD(String, pimpatentid);
    DTO_FIELD_INFO(pimpatentid) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentid");
    }

    //ZLHQSJ : ר����ȡʱ��
    DTO_FIELD(String, zlhqsj);
    DTO_FIELD_INFO(zlhqsj) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlhqsj");
    }
    
    //PIMPATENTNAME : ר������
    DTO_FIELD(String, pimpatentname);
    DTO_FIELD_INFO(pimpatentname) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpatentname");
    }

    //UPDATEMAN : ������
    DTO_FIELD(String, updateman);
    DTO_FIELD_INFO(updateman) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.updateman");
    }
    
    //CREATEMAN : ������
    DTO_FIELD(String, createman);
    DTO_FIELD_INFO(createman) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.createman");
    }
    
    //CREATEDATE : ����ʱ��
    DTO_FIELD(String, createdate);
    DTO_FIELD_INFO(createdate) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.createdate");
    }
    
    //ZLPZGB : ר����׼����
    DTO_FIELD(String, zlpzgb);
    DTO_FIELD_INFO(zlpzgb) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.zlpzgb");
    }
    
    //PIMPERSONID : ��Ա��Ϣ��ʶ
    DTO_FIELD(String, pimpersonid);
    DTO_FIELD_INFO(pimpersonid) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.pimpersonid");
    }
    
    //JLSS : ��¼����
    DTO_FIELD(String, jlss);
    DTO_FIELD_INFO(jlss) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlss");
    }
    
    //JLSPZT : ����״̬
    DTO_FIELD(String, jlspzt);
    DTO_FIELD_INFO(jlspzt) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlspzt");
    }
    
    //JLGLBH : ��¼�������
    DTO_FIELD(String, jlglbh);
    DTO_FIELD_INFO(jlglbh) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlglbh");
    }
    
    //JLCZZ : ��¼������
    DTO_FIELD(String, jlczz);
    DTO_FIELD_INFO(jlczz) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.jlczz");
    }
    
    //ENCLOLURE : ����
    DTO_FIELD(String, enclolure);
    DTO_FIELD_INFO(enclolure) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.enclolure");
    }
    
    //REASON : �ܾ�ԭ��
    DTO_FIELD(String, reason);
    DTO_FIELD_INFO(reason) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.reason");
    }

};

/**
 * ��ҳ�������
 */
class PatentinfoPageDTO : public PageDTO<PatentinfoDTO::Wrapper>
{
    DTO_INIT(PatentinfoPageDTO, PageDTO<PatentinfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_