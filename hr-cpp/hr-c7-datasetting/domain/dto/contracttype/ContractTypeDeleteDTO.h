#pragma once
#ifndef _CONTRACTTYPE_DELETE_DTO_
#define _CONTRACTTYPE_DELETE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ContractTypeDeleteDTO : public oatpp::DTO
{
	DTO_INIT(ContractTypeDeleteDTO, DTO);

	// 待删除合同类别的ID列表
	DTO_FIELD(List<Int64>, ids);
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("contractType.field.ids");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif