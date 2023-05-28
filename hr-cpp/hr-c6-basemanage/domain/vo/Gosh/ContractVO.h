#pragma once
#ifndef _Contract_VO_
#define _Contract_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Gosh/ContractDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ContractJsonVO : public JsonVO<ContractDTO_gs::Wrapper> {
	DTO_INIT(ContractJsonVO, JsonVO<ContractDTO_gs::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ContractPageJsonVO : public JsonVO<ContractPageDTO_gs::Wrapper> {
	DTO_INIT(ContractPageJsonVO, JsonVO<ContractPageDTO_gs::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_