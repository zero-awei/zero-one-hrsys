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
	//签约主体单位标识CONTRACTSIGNORGID
	DTO_FIELD(List<String>, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DELETE_LEGAL_ENTITY_QUERY_