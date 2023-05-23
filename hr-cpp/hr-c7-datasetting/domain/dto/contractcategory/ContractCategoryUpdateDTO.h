#pragma once
#ifndef _CONTRACTCATEGORY_UPDATE_DTO_
#define _CONTRACTCATEGORY_UPDATE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ContractCategoryUpdateDTO : public oatpp::DTO
{
	DTO_INIT(ContractCategoryUpdateDTO, DTO);
	// 合同类型ID
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.id");
	}
	// 合同类型名称
	DTO_FIELD(String, categoryName);
	DTO_FIELD_INFO(categoryName) {
		info->description = ZH_WORDS_GETTER("contractCategory.field.categoryName");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_
