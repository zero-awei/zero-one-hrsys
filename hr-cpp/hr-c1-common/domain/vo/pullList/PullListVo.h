#pragma once
#ifndef _PULLLISTVO_H_
#define _PULLLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/pullList/PullListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PullListVO : public JsonVO<PullListDTO::Wrapper>
{
	DTO_INIT(PullListVO, JsonVO<PullListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PULLLISTVO_H_