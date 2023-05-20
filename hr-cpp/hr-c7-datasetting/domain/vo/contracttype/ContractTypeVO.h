#pragma once
#ifndef _CONTRACT_TYPE_VO_
#define _CONTRACT_TYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/contractType/ContractTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 合同类别显示JsonVO，用于响应给客户端的Json对象
 */
class ContractTypeJsonVO : public JsonVO<ContractTypeDTO::Wrapper> {
	DTO_INIT(ContractTypeJsonVO, JsonVO<ContractTypeDTO::Wrapper>);
};

/**
 * 合同类别分页显示JsonVO，用于响应给客户端的Json对象
 */
class ContractTypePageJsonVO : public JsonVO<ContractTypePageDTO::Wrapper> {
	DTO_INIT(ContractTypePageJsonVO, JsonVO<ContractTypePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CONTRACT_TYPE_VO_
