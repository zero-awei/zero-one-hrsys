#pragma once
/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_VO_
#define _DELETE_LEGAL_ENTITY_VO_

#include "../../GlobalInclude.h"
#include "../../dto/LegalEntitySet/DeleteLegalEntityDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class DeleteLegalEntityJsonVO : public JsonVO<DeleteLegalEntityDTO::Wrapper> {
	DTO_INIT(DeleteLegalEntityJsonVO, JsonVO<DeleteLegalEntityDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class DeleteLegalEntityPageJsonVO : public JsonVO<DeleteLegalEntityPageDTO::Wrapper> {
	DTO_INIT(DeleteLegalEntityPageJsonVO, JsonVO<DeleteLegalEntityPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 