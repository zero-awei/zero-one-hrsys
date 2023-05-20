#pragma once
#ifndef _CONTRACTTYPE_UPDATE_RESULT_VO_
#define _CONTRACTTYPE_UPDATE_RESULT_VO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ContractTypeUpdateResultVO : public oatpp::DTO
{
	DTO_INIT(ContractTypeUpdateResultVO, DTO);
	// ÊÇ·ñ³É¹¦
	DTO_FIELD(Boolean, success);
	DTO_FIELD_INFO(success) {
		info->description = ZH_WORDS_GETTER("contractType.field.success");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTTYPE_UPDATE_RESULT_VO_
