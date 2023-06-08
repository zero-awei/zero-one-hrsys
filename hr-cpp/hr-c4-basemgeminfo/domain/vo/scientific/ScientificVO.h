#pragma once
#ifndef _SCIENTIFICVO_H_
#define _SCIENTIFICVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/scientific/ScientificDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class ScientificJsonVO :public JsonVO<ScientificDTO::Wrapper> {
	DTO_INIT(ScientificJsonVO, JsonVO<ScientificDTO::Wrapper>);
};

class ScientificPageJsonVO : public JsonVO<ScientificPageDTO::Wrapper>
{
	DTO_INIT(ScientificPageJsonVO, JsonVO<ScientificPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SCIENTIFICVO_H_