#pragma once
#ifndef _PAPER_VO_
#define _PAPER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/paperinfo/PaperDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 论文信息显示JsonVO，用于响应给客户端的Json对象
 */
class PaperJsonVO : public JsonVO<PaperDTO::Wrapper> {
	DTO_INIT(PaperJsonVO, JsonVO<PaperDTO::Wrapper>);
};

/**
 * 论文信息分页显示JsonVO，用于响应给客户端的Json对象
 */
class PaperPageJsonVO : public JsonVO<PaperPageDTO::Wrapper> {
	DTO_INIT(PaperPageJsonVO, JsonVO<PaperPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 