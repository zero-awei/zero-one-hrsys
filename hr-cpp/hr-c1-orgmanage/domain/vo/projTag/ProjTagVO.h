#pragma once
#ifndef _PROJTAG_VO_
#define _PROJTAG_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/projTag/ProjTagDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 项目标签信息
 * 负责人：远翔
 */
class ProjTagJsonVO : public JsonVO<ProjTagDTO::Wrapper> {
	DTO_INIT(ProjTagJsonVO, JsonVO<ProjTagDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_PROJTAG_VO_