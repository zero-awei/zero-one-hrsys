#pragma once
/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_DTO_
#define _DELETE_LEGAL_ENTITY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class DeleteLegalEntityDTO : public oatpp::DTO
{
public:
	//无参构造
	DeleteLegalEntityDTO() {};
	DTO_INIT(DeleteLegalEntityDTO, DTO);
	//法人主体标识ORMSIGNORGID
	DTO_FIELD(List<String>, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}

};

/**
 * 示例分页传输对象
 */
class DeleteLegalEntityPageDTO : public PageDTO<DeleteLegalEntityDTO::Wrapper>
{
	DTO_INIT(DeleteLegalEntityPageDTO, PageDTO<DeleteLegalEntityDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 