#pragma once
#ifndef _CHECK_RETIRES_VO_
#define _CHECK_RETIRES_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/CheckRetiresListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CheckRetiresListJsonVO : public JsonVO<CheckRetiresListDTO::Wrapper> {
	DTO_INIT(CheckRetiresListJsonVO, JsonVO<CheckRetiresListDTO::Wrapper>);
};

class CheckRetiresListPageJsonVO : public JsonVO<CheckRetiresListPageDTO::Wrapper> {
	DTO_INIT(CheckRetiresListPageJsonVO, JsonVO<CheckRetiresListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 