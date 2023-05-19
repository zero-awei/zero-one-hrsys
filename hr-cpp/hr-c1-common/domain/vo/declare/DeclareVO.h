#pragma once
#ifndef _DECLARE_VO_
#define _DECLARE_VO_
#include "../../GlobalInclude.h"
#include "../../dto/declare/DeclareDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeclareListJsonVO : public JsonVO<DeclareDTO::Wrapper> {
	DTO_INIT(DeclareListJsonVO, JsonVO<DeclareDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif