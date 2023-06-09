#pragma once


#ifndef _DELPATENT_DTO_
#define _DELPATENT_DTO_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 专利信息传输对象
 */
class DelPatentDTO : public oatpp::DTO
{

public:
    DTO_INIT(DelPatentDTO, DTO);
    DTO_FIELD(List<String>, deleteById) = {};
    DTO_FIELD_INFO(deleteById) {
        info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTID");
    }
    
    DTO_INIT_(String, pimpatentid, "patentInformation.pimpatent.PIMPATENTID");
    ////人员信息id
    //DTO_FIELD(String, pimpatentid);
    //DTO_FIELD_INFO(pimpatentid) {
    //    info->description = ZH_WORDS_GETTER("patentInformation.pimpatent.PIMPATENTID");
    //}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
