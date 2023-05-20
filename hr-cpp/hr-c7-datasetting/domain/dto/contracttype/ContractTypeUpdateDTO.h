#pragma once
#ifndef _CONTRACTTYPE_UPDATE_DTO_
#define _CONTRACTTYPE_UPDATE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ContractTypeUpdateDTO : public oatpp::DTO
{
	DTO_INIT(ContractTypeUpdateDTO, DTO);
	// 合同类型ID
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("contractType.field.id");
	}
	// 合同类型名称
	DTO_FIELD(String, typeName);
	DTO_FIELD_INFO(typeName) {
		info->description = ZH_WORDS_GETTER("contractType.field.typeName");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTTYPE_UPDATE_DTO_
