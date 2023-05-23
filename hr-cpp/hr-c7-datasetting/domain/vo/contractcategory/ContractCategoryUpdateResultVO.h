#pragma once
#ifndef _CONTRACTCATEGORY_UPDATE_RESULT_VO_
#define _CONTRACTCATEGORY_UPDATE_RESULT_VO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ContractCategoryUpdateResultVO : public oatpp::DTO
{
	DTO_INIT(ContractCategoryUpdateResultVO, DTO);
	// ÊÇ·ñ³É¹¦
	DTO_FIELD(Boolean, success);
	DTO_FIELD_INFO(success) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.success");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_
