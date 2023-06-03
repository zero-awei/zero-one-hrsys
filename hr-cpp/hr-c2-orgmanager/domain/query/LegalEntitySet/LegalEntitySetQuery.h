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
	// 法人主体标识
	DTO_FIELD(String, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}
	// 签约主体单位名称
	DTO_FIELD(String, contractsignorgname);
	DTO_FIELD_INFO(contractsignorgname) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgname");
	}
	//  默认签约主体
	DTO_FIELD(String, isdefaultsignorg);
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
	// 签约主体单位标识
	DTO_FIELD(String, contractsignorgid);
	DTO_FIELD_INFO(contractsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.contractsignorgid");
	}
	// 管理单位标识
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormorgid");
	}
	//// 更新人
	//DTO_FIELD(String, updateman);
	//DTO_FIELD_INFO(updateman) {
	//	info->description = ZH_WORDS_GETTER("LegalEntitySet.field.updateman");
	//}
	//// 建立人
	//DTO_FIELD(String, createman);
	//DTO_FIELD_INFO(createman) {
	//	info->description = ZH_WORDS_GETTER("LegalEntitySet.field.createman");
	//}
	//// 建立时间
	//DTO_FIELD(String, createdate);
	//DTO_FIELD_INFO(createdate) {
	//	info->description = ZH_WORDS_GETTER("LegalEntitySet.field.createdate");
	//}
	//// 更新时间
	//DTO_FIELD(String, updatedate);
	//DTO_FIELD_INFO(updatedate) {
	//	info->description = ZH_WORDS_GETTER("LegalEntitySet.field.updatedate");
	//}

	// 法人主体标识
	/*DTO_FIELD(String, signorgid);
	DTO_FIELD_INFO(signorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.signorgid");
	}*/
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSET_QUERY_
