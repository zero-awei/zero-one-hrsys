#pragma once
#ifndef _LEGALERNAMEPULLDOWNLIST_DTO_
#define _LEGALERNAMEPULLDOWNLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class LegalerNamePullDownListDTO : public oatpp::DTO {
	DTO_INIT(LegalerNamePullDownListDTO, DTO);
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
class LegalerNamePullDownListPageDTO : public PageDTO<LegalerNamePullDownListDTO::Wrapper> {
	DTO_INIT(LegalerNamePullDownListPageDTO, PageDTO<LegalerNamePullDownListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LEGALERNAMEPULLDOWNLIST_DTO_