#pragma once
#ifndef _DECLARE_DTO_
#define _DECLARE_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class DeclareDTO : public oatpp::DTO 
{
	DTO_INIT(DeclareDTO, DTO);
	DTO_FIELD(String, declaretype);
	DTO_FIELD_INFO(declaretype) {
		info->description = ZH_WORDS_GETTER("t_pcmprofile.field.declaretype");
	}
};
class DeclarePageDTO : public PageDTO<DeclareDTO::Wrapper>
{
	DTO_INIT(DeclarePageDTO, PageDTO<DeclareDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DECLARE_DTO_
