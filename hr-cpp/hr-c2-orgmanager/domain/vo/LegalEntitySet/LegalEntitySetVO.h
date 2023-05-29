#pragma once
#pragma once
#ifndef _LEGALERNAMEPULLDOWNLIST_VO_
#define _LEGALERNAMEPULLDOWNLIST_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/LegalEntitySetDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class LegalEntitySetJsonVO : public JsonVO<LegalEntitySetDTO::Wrapper> {
	DTO_INIT(LegalEntitySetJsonVO, JsonVO<LegalEntitySetDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class LegalEntitySetPageJsonVO : public JsonVO<LegalEntitySetPageDTO::Wrapper> {
	DTO_INIT(LegalEntitySetPageJsonVO, JsonVO<LegalEntitySetPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALERNAMEPULLDOWNLIST_VO_