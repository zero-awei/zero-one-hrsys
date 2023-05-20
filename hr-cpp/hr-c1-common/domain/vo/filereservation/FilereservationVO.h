#pragma once

#ifndef _FILERESERVATION_VO_
#define _FILERESERVATION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/sample/SampleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 档案状态显示JsonVO，用于响应给客户端的Json对象
 */
class FilereservationJsonVO : public JsonVO<SampleDTO::Wrapper> {
	DTO_INIT(FilereservationJsonVO, JsonVO<SampleDTO::Wrapper>);
};

/**
 * 档案状态分页显示JsonVO，用于响应给客户端的Json对象
 */
class FilereservationPageJsonVO : public JsonVO<SamplePageDTO::Wrapper> {
	DTO_INIT(FilereservationPageJsonVO, JsonVO<SamplePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILERESERVATION_VO_