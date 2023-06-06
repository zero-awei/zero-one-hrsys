#pragma once
#ifndef _CONTRACTCATEGORYVO_H_
#define _CONTRACTCATEGORYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/contractcategory/ContractCategoryDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 合同类别显示JsonVO
 */
class ContractCategoryJsonVO : public JsonVO<ContractCategoryDTO::Wrapper>
{
    DTO_INIT(ContractCategoryJsonVO, JsonVO<ContractCategoryDTO::Wrapper>);
};

/**
 * 合同类别分页显示JsonVO
 */
class ContractCategoryPageJsonVO : public JsonVO<ContractCategoryPageDTO::Wrapper>
{
    DTO_INIT(ContractCategoryPageJsonVO, JsonVO<ContractCategoryPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACTCATEGORYVO_H_
