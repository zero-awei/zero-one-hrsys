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
	// 法人主体名称
	DTO_FIELD(String, ormsignorgname);
	DTO_FIELD_INFO(ormsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.name");
	}
	// 签约主体单位名称
	DTO_FIELD(String, contractsignorgname);
	DTO_FIELD_INFO(contractsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
	}
	// 默认签约主体
	DTO_FIELD(UInt64, isdefaultsignorg);
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CheckCerList_QUERY_