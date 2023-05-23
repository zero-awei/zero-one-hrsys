#pragma once
#ifndef _CONTRACT_CATEGORY_VO_
#define _CONTRACT_CATEGORY_VO_

#include "../../GlobalInclude.h"
#include "../../dto/contractcategory/ContractCategoryDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 合同类别显示JsonVO，用于响应给客户端的Json对象
 */
class ContractCategoryJsonVO : public JsonVO<ContractCategoryDTO::Wrapper> {
	DTO_INIT(ContractCategoryJsonVO, JsonVO<ContractCategoryDTO::Wrapper>);
};

/**
 * 合同类别分页显示JsonVO，用于响应给客户端的Json对象
 */
class ContractCategoryPageJsonVO : public JsonVO<ContractCategoryPageDTO::Wrapper> {
	DTO_INIT(ContractCategoryPageJsonVO, JsonVO<ContractCategoryPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_
