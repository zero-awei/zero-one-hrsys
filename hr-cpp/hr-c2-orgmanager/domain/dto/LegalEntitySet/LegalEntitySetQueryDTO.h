#pragma once

/*
组织管理 —— 数据设置 —— 法人主体设置  -- cpt

法人主体名称下拉列表 `LegalEntitySetPullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `LegalEntitySet`

新增法人设置（支持批量新增）** `LegalEntitySet`
*/

#ifndef _LEGALENTITYSETQUERY_DTO_
#define _LEGALENTITYSETQUERY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class LegalEntitySetQueryDTO : public oatpp::DTO {
public:
	LegalEntitySetQueryDTO() {};
	LegalEntitySetQueryDTO(String ormsignorgid, String ormorgid, String signorgid, String isdefaultsignorg) : ormorgid(ormorgid), signorgid(signorgid), isdefaultsignorg(isdefaultsignorg) {};
	DTO_INIT(LegalEntitySetQueryDTO, DTO);
	// 法人主体标识
	DTO_FIELD(String, ormsignorgid);
	DTO_FIELD_INFO(ormsignorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormsignorgid");
	}
	// 管理单位标识
	DTO_FIELD(String, ormorgid);
	DTO_FIELD_INFO(ormorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.ormorgid");
	}
	// 法人主体标识
	DTO_FIELD(String, signorgid);
	DTO_FIELD_INFO(signorgid) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.signorgid");
	}
	// // 默认签约主体
	DTO_FIELD(String, isdefaultsignorg);
	DTO_FIELD_INFO(isdefaultsignorg) {
		info->description = ZH_WORDS_GETTER("LegalEntitySet.field.isdefaultsignorg");
	}
};

/**
 * 示例分页传输对象
 */
class LegalEntitySetQueryPageDTO : public PageDTO<LegalEntitySetQueryDTO::Wrapper> {
	DTO_INIT(LegalEntitySetQueryPageDTO, PageDTO<LegalEntitySetQueryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSETQUERY_DTO_