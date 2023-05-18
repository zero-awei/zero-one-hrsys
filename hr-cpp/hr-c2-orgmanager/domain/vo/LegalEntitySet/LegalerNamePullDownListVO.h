#pragma once
#ifndef _LEGALERNAMEPULLDOWNLIST_VO_
#define _LEGALERNAMEPULLDOWNLIST_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/LegalerNamePullDownListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class LegalerNamePullDownListJsonVO : public JsonVO<LegalerNamePullDownListDTO::Wrapper> {
	DTO_INIT(LegalerNamePullDownListJsonVO, JsonVO<LegalerNamePullDownListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class LegalerNamePullDownListPageJsonVO : public JsonVO<LegalerNamePullDownListDTO::Wrapper> {
	DTO_INIT(LegalerNamePullDownListPageJsonVO, JsonVO<LegalerNamePullDownListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LEGALERNAMEPULLDOWNLIST_VO_