#pragma once

#ifndef _CONTRACT_TYPE_CREATE_DTO_
#define _CONTRACT_TYPE_CREATE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ContractTypeCreateDTO : public oatpp::DTO
{
	DTO_INIT(ContractTypeCreateDTO, DTO);

	DTO_FIELD(String, typeName);
	DTO_FIELD_INFO(typeName) {
		info->description = ZH_WORDS_GETTER("contractTypeCreate.field.typeName");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACT_TYPE_CREATE_DTO_