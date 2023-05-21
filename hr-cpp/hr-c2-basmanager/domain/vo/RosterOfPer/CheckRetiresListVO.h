#pragma once
#ifndef _CHECK_RETIRES_VO_
#define _CHECK_RETIRES_VO_

#include "../../GlobalInclude.h"
#include "../../dto/RosterOfPer/CheckRetiresListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class CheckRetiresListJsonVO : public JsonVO<CheckRetiresListDTO::Wrapper> {
	DTO_INIT(CheckRetiresListJsonVO, JsonVO<CheckRetiresListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class CheckRetiresListPageJsonVO : public JsonVO<CheckRetiresListPageDTO::Wrapper> {
	DTO_INIT(CheckRetiresListPageJsonVO, JsonVO<CheckRetiresListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 