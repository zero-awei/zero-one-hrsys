#pragma once
/**
* 法人主体设置--删除法人设置(支持批量删除)--pine
 */
#ifndef _DELETE_LEGAL_ENTITY_QUERY_
#define _DELETE_LEGAL_ENTITY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

 /**
* 法人主体设置--删除法人设置(支持批量删除)--pine
  */
class DeleteLegalEntityQuery : public PageQuery
{
	DTO_INIT(DeleteLegalEntityQuery, PageQuery);
	//法人主体标识ORMSIGNORGID
	DTO_FIELD(List<String>, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CheckCerList_QUERY_