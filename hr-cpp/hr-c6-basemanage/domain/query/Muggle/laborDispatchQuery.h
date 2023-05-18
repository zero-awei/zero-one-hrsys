#pragma once
#ifndef _LB_M_QUERY_
#define _LB_M_QUERY
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class LaborDispatchMQuery : public oatpp::DTO
{
	DTO_INIT(LaborDispatchMQuery, DTO);
	// ¹«Ë¾Ãû³Æ
	DTO_FIELD(String, corporateName);
	DTO_FIELD_INFO(corporateName) {
		info->description = ZH_WORDS_GETTER("labordispatch_mug.field.corporatename");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_LB_M_QUERY_
