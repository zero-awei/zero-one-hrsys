#pragma once
/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#ifndef _DELETE_LEGAL_ENTITY_DTO_
#define _DELETE_LEGAL_ENTITY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeleteLegalEntityDTO : public oatpp::DTO
{
public:
	//无参构造
	DeleteLegalEntityDTO() {};
	DTO_INIT(DeleteLegalEntityDTO, DTO);
	//签约主体单位标识
	DTO_FIELD(List<String>, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}

};

class DeleteLegalEntityPageDTO : public PageDTO<DeleteLegalEntityDTO::Wrapper>
{
	DTO_INIT(DeleteLegalEntityPageDTO, PageDTO<DeleteLegalEntityDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 