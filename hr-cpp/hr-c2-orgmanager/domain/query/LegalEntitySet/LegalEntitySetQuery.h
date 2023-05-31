#pragma once

#ifndef _LEGALENTITYSET_QUERY_
#define _LEGALENTITYSET_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
组织管理 ——数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/
class LegalEntitySetQuery : public PageQuery
{
	DTO_INIT(LegalEntitySetQuery, PageQuery);
	// 法人主体名称
	DTO_FIELD(String, ormsignorgname);
	DTO_FIELD_INFO(ormsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgname");
	}
	// 签约主体单位名称
	DTO_FIELD(String, contractsignorgname);
	DTO_FIELD_INFO(contractsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
	}
	// 默认签约主体
	DTO_FIELD(String, isdefaultsignorg);
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSET_QUERY_