#pragma once
#ifndef _DECLARE_DTO_
#define _DECLARE_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class DeclareDTO : public oatpp::DTO
{
	DTO_INIT(DeclareDTO, DTO);

	DTO_FIELD(UInt32, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("declare.code");
	}
	DTO_FIELD(String, declaretype);
	DTO_FIELD_INFO(declaretype) {
		info->description = ZH_WORDS_GETTER("declare.type");
	}
public:
	DeclareDTO()
	{
		code = 1;
		declaretype = "A";
	}

	DeclareDTO(Int32 num, String type)
	{
		code = num;
		declaretype = type;
	}
};

class DeclareTypeListDTO : public oatpp::DTO
{
	DTO_INIT(DeclareTypeListDTO, DTO);
	DTO_FIELD_INFO(declareList) {
		info->description = ZH_WORDS_GETTER("common.dto.declarelist");
	}
	DTO_FIELD(List<DeclareDTO::Wrapper>, declareList) = {};
};

#include OATPP_CODEGEN_END(DTO)
#endif