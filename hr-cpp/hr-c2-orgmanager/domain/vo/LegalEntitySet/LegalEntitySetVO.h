#pragma once

#ifndef _LEGALENTITYSET_VO_
#define _LEGALENTITYSET_VO_

/*
*（	数据设置——法人主体设置 ——  cpt

法人主体名称下拉列表 `LegalerNamePullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `ExportLegalerSeting`

新增法人设置（支持批量新增）** `AddLegalerSeting`
*/


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

#endif // !_LEGALENTITYSET_VO_