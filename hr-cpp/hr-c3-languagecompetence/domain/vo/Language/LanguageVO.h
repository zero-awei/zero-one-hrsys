#pragma once
#ifndef _LANGUAGE_VO_
#define _LANGUAGE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Language/LanguageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class LanguageJsonVO : public JsonVO<LanguageDTO::Wrapper> {
	DTO_INIT(LanguageJsonVO, JsonVO<LanguageDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class LanguagePageJsonVO : public JsonVO<LanguagePageDTO::Wrapper> {
	DTO_INIT(LanguagePageJsonVO, JsonVO<LanguagePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LANGUAGE_VO_