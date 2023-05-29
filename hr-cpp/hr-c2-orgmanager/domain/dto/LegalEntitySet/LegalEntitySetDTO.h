#pragma once

/*
*  组织管理 ——法人主体设置  -- cpt
法人主体名称下拉列表 `LegalerNamePullDownList`

更新指定法人设置信息  `UpdateLegalerSettingMessage`

导出法人设置 `ExportLegalerSeting`

**新增法人设置（支持批量新增）** `LegalEntitySet`
*/

#ifndef _LEGALENTITYSET_DTO_
#define _LEGALENTITYSET_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class LegalEntitySetDTO : public oatpp::DTO {
	DTO_INIT(LegalEntitySetDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 年龄
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
};

/**
 * 示例分页传输对象
 */
class LegalEntitySetPageDTO : public PageDTO<LegalEntitySetDTO::Wrapper> {
	DTO_INIT(LegalEntitySetPageDTO, PageDTO<LegalEntitySetDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALENTITYSET_DTO_