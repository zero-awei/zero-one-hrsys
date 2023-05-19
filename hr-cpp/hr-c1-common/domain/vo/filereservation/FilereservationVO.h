#pragma once

#ifndef _FILERESERVATION_VO_
#define _FILERESERVATION_VO_

#include "../../GlobalInclude.h"

#include "domain/dto/pullList/PullListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 档案保管地下拉列表显示JsonVO，用于响应给客户端的Json对象
 * 负责人：远翔
 */
class FilereservationJsonVO : public JsonVO<PullListDTO::Wrapper> {
	DTO_INIT(FilereservationJsonVO, JsonVO<PullListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILERESERVATION_VO_