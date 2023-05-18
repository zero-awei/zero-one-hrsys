#pragma once
#ifndef _EXPORTLEGALERSETTING_DTO_
#define _EXPORTLEGALERSETTING_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportLegalerSetingDTO : public oatpp::DTO {
	DTO_INIT(ExportLegalerSetingDTO, DTO);
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
class ExportLegalerSetingPageDTO : public PageDTO<ExportLegalerSetingDTO::Wrapper> {
	DTO_INIT(ExportLegalerSetingPageDTO, PageDTO<ExportLegalerSetingDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTLEGALERSETTING_DTO_