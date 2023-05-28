#pragma once
/*
*（数据设置——法人主体设置——导出法人主体设置 (导出页面在前端完成) --cpt
*/

#ifndef _ADDLEGALERSETTING_VO_
#define _ADDLEGALERSETTING_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/LegalEntitySet/AddLegalerSetingDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class AddLegalerSetingJsoonVO : public JsonVO<AddLegalerSetingDTO::Wrapper> {
	DTO_INIT(AddLegalerSetingJsoonVO, JsonVO<AddLegalerSetingDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class AddLegalerSetingPageJsonVO : public JsonVO<AddLegalerSetingDTO::Wrapper> {
	DTO_INIT(AddLegalerSetingPageJsonVO, JsonVO<AddLegalerSetingDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDLEGALERSETTING_VO_