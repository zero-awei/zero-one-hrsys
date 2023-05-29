#pragma once
#ifndef _EXPORTLEGALERSETTING_VO_
#define _EXPORTLEGALERSETTING_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/ExportLegalerSetingDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ExportLegalerSetingJsoonVO : public JsonVO<ExportLegalerSetingDTO::Wrapper> {
	DTO_INIT(ExportLegalerSetingJsoonVO, JsonVO<ExportLegalerSetingDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ExportLegalerSetingPageJsonVO : public JsonVO<ExportLegalerSetingPageDTO::Wrapper> {
	DTO_INIT(ExportLegalerSetingPageJsonVO, JsonVO<ExportLegalerSetingPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTLEGALERSETTING_VO_