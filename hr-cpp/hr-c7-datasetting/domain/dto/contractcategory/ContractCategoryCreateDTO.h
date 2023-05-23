#pragma once
#ifndef _CONTRACT_CATEGORY_CREATE_DTO_
#define _CONTRACT_CATEGORY_CREATE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ContractCategoryCreateDTO : public oatpp::DTO
{
	DTO_INIT(ContractCategoryCreateDTO, DTO);

	DTO_FIELD(String, categoryName);
	DTO_FIELD_INFO(categoryName) {
		info->description = ZH_WORDS_GETTER("contractCategoryCreate.field.categoryName");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !