#pragma once
#ifndef _DECLARE_LIST_
#define _DECLARE_LIST_

#include "../../GlobalInclude.h"
#include "../../dto/declareType/DeclareTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeclareListVO : public JsonVO<DeclareTypeListDTO::Wrapper>
{
	DTO_INIT(DeclareListVO, JsonVO<DeclareTypeListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif