#pragma once
#ifndef _RRAINEE_VO_
#define _RRAINEE_VO_
#include "../../GlobalInclude.h"
#include "domain/dto/RosterOfPer/RraineeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  基础管理 —— 人员花名册 —— 见习员工   ——Cpt
 */
/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class RraineeJsonVO : public JsonVO<RraineeDTO::Wrapper> {
	DTO_INIT(RraineeJsonVO, JsonVO<RraineeDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
	class RraineePageJsonVO : public JsonVO<RraineeDTO::Wrapper> {
		DTO_INIT(RraineePageJsonVO, JsonVO<RraineeDTO::Wrapper>);
	};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RRAINEE_VO_