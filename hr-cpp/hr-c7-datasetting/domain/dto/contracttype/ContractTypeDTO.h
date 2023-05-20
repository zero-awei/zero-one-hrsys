#pragma once
#ifndef _CONTRACT_TYPE_DTO_
#define _CONTRACT_TYPE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 合同类别传输对象
 */
class ContractTypeDTO : public oatpp::DTO
{
	DTO_INIT(ContractTypeDTO, DTO);
	// 类别ID
	DTO_FIELD(UInt64, typeId);
	DTO_FIELD_INFO(typeId) {
		info->description = ZH_WORDS_GETTER("contractType.field.typeId");
	}
	// 类别名称
	DTO_FIELD(String, typeName);
	DTO_FIELD_INFO(typeName) {
		info->description = ZH_WORDS_GETTER("contractType.field.typeName");
	}
	// 类别描述
	DTO_FIELD(String, typeDescription);
	DTO_FIELD_INFO(typeDescription) {
		info->description = ZH_WORDS_GETTER("contractType.field.typeDescription");
	}
};

/**
 * 合同类别分页传输对象
 */
class ContractTypePageDTO : public PageDTO<ContractTypeDTO::Wrapper>
{
	DTO_INIT(ContractTypePageDTO, PageDTO<ContractTypeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CONTRACT_TYPE_DTO_
