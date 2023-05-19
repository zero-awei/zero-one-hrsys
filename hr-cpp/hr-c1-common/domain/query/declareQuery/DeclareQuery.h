#pragma once
#ifndef _DECLARE_QUERY_
#define _DECLARE_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeclareQuery : public oatpp::DTO
{
	DTO_INIT(DeclareQuery, oatpp::DTO);
	DTO_FIELD(UInt32, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("declare.code");
	}
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("declare.type");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DECLARE_QUERY_
