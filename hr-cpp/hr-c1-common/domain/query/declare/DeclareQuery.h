#pragma once
#ifndef _DECLARE_QUERY_
#define _DECLARE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class DeclareQuery : public PageQuery
{
	DTO_INIT(DeclareQuery, DTO);
	// Éê±¨
	DTO_FIELD(String, declare);
	DTO_FIELD_INFO(declare) {
		info->description = ZH_WORDS_GETTER("t_pcmprofile.field.declaretype");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_DECLARE_QUERY_
