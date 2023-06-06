#pragma once
#ifndef _J_PAPER_VO_
#define _J_PAPER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/J_paperinfo/J_PaperinfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 论文信息显示JsonVO，用于响应给客户端的Json对象
 */
class PaperJsonVO : public JsonVO<PaperinfoDTO::Wrapper> {
	DTO_INIT(PaperJsonVO, JsonVO<PaperinfoDTO::Wrapper>);
};

class PaperinfoJsonVO : public JsonVO<PaperinfoDTO::Wrapper> {
	DTO_INIT(PaperinfoJsonVO, JsonVO<PaperinfoDTO::Wrapper>);
};



/**
 * 论文信息分页显示JsonVO，用于响应给客户端的Json对象
 */
class PaperPageJsonVO : public JsonVO<PaperinfoPageDTO::Wrapper> {
	DTO_INIT(PaperPageJsonVO, JsonVO<PaperinfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 