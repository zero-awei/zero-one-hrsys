#pragma once
#ifndef _RETIREMENTVO_H_
#define _RETIREMENTVO_H_

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/dto/retirement/RetiremetDto.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class RetirementJsonVO : public JsonVO<RetirementDTO::Wrapper> {
	DTO_INIT(RetirementJsonVO, JsonVO<RetirementDTO::Wrapper>);
};

// 分页查询返回的JsonVO
class RetirementQueryPageJsonVO :public JsonVO<RetirementPageDTO::Wrapper> {
	DTO_INIT(RetirementQueryPageJsonVO, JsonVO<RetirementPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_RETIREMENTVO_H_


