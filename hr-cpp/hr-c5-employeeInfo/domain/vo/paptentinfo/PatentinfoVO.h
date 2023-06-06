#pragma once
#ifndef _PATENT_VO_
#define _PATENT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/patentinfo/PatentinfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 论文信息显示JsonVO，用于响应给客户端的Json对象
 */
class PatentinfoJsonVO : public JsonVO<PatentinfoDTO::Wrapper> {
	DTO_INIT(PatentinfoJsonVO, JsonVO<PatentinfoDTO::Wrapper>);
};

/**
 * 论文信息分页显示JsonVO，用于响应给客户端的Json对象
 */
class PatentinfoPageJsonVO : public JsonVO<PatentinfoPageDTO::Wrapper> {
	DTO_INIT(PatentinfoPageJsonVO, JsonVO<PatentinfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 