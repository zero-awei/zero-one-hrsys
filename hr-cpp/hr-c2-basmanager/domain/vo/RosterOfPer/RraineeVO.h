#pragma once
#ifndef _RRAINEE_VO_
#define _RRAINEE_VO_
#include "../../GlobalInclude.h"
#include "domain/dto/RosterOfPer/RraineeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  基础管理 —— 人员花名册 —— 见习员工   ——Cpt
 */

class RraineeJsonVO : public JsonVO<RraineeDTO::Wrapper> {
	DTO_INIT(RraineeJsonVO, JsonVO<RraineeDTO::Wrapper>);
};

class RraineePageJsonVO : public JsonVO<RraineePageDTO::Wrapper> {
	DTO_INIT(RraineePageJsonVO, JsonVO<RraineePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RRAINEE_VO_