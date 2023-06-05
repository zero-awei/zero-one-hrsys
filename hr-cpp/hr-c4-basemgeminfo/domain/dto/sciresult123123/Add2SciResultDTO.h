#pragma once
#ifndef _ADD2SCIRESULTDTO_H_
#define _ADD2SCIRESULTDTO_H_

#define DTO_INIT_(type, field, name) \
DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 
 */
class Add2SciResultDTO : public oatpp::DTO
{
	DTO_INIT(Add2SciResultDTO, DTO);
	//科研成果名称
	DTO_INIT_(String, PIMRESEARCHFINDINGSNAME, "sciresult.PIMRESEARCHFINDINGSNAME");
	//获取时间
	DTO_INIT_(String, HQSJ, "sciresult.HQSJ");
	//附件
	DTO_INIT_(String, FJ, "sciresult.FJ");
	//人员信息标识
	DTO_INIT_(String, PIMPERSONID, "sciresult.PIMPERSONID");
	
};

#include OATPP_CODEGEN_END(DTO)

#undef DTO_INIT_

#endif // !_ADDWORKHISTORYDTO_H_