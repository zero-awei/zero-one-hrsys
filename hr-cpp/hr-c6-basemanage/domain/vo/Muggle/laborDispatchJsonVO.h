#pragma once
#ifndef _M_LDJ_VO_
#define _M_LDJ_VO_
#include "../../GlobalInclude.h"
#include "domain/vo/JsonVO.h"
#include "../../dto/Muggle/laborDispatchDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class LaborDispatchJsonMVO : public JsonVO<LaborDispatchMDTO::Wrapper>
{
	DTO_INIT(LaborDispatchJsonMVO, JsonVO<LaborDispatchMDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_M_LDJ_VO_
