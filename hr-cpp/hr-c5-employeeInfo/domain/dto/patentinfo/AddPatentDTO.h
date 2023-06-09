#pragma once


#ifndef _ADDPATENT_DTO_
#define _ADDPATENT_DTO_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 添加专利信息传输对象
 */
class AddPatentDTO : public oatpp::DTO
{

public:
    AddPatentDTO() {};
    DTO_INIT(AddPatentDTO, DTO);

    //ZLH:专利号
    DTO_FIELD(String, zlh);
    DTO_FIELD_INFO(zlh) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLH");
    }

    //PIMPATENTNAME : 专利名称
    DTO_FIELD(String, pimpatentname);
    DTO_FIELD_INFO(pimpatentname) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTNAME");
    }

    //ZLHQSJ : 专利获取时间
    DTO_FIELD(String, zlhqsj);
    DTO_FIELD_INFO(zlhqsj) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLHQSJ");
    }

    //ZLPZGB : 专利批准国别
    DTO_FIELD(String, zlpzgb);
    DTO_FIELD_INFO(zlpzgb) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ZLPZGB");
    }

    //ENCLOLURE : 附件
    DTO_FIELD(String, enclolure);
    DTO_FIELD_INFO(enclolure) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.ENCLOLURE");
    }

    ////建立时间
    //DTO_INIT_(String, creatdate, "patentInformation.pimpatent.CREATEDATE")

    ////更新时间
    //DTO_INIT_(String, updatedate, "patentInformation.pimpatent.UPDATEDATE")

    ////更新人
    //DTO_INIT_(String, createman, "patentInformation.pimpatent.CREATEMAN")

    ////建立时间
    //DTO_INIT_(String, updateman, "patentInformation.pimpatent.UPDATEMAN")

    //专利信息编码
    DTO_INIT_(String, pimpatentid, "patentInformation.pimpatent.PIMPATENTID")
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
