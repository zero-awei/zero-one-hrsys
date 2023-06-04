#pragma once
/*
(法人主体设置-导入法人设置)--洛洛
*/
#ifndef _IMPORTLEAGALPERSETTING_DTO_
#define _IMPORTLEAGALPERSETTING_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ImportLeagalPerSettingDTO : public oatpp::DTO
{
	DTO_INIT(ImportLeagalPerSettingDTO, DTO);
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

//class SamplePageDTO : public PageDTO<ImportLeagalPerSettingDTO::Wrapper>
//{
//	DTO_INIT(SamplePageDTO, PageDTO<ImportLeagalPerSettingDTO::Wrapper>);
//};

#include OATPP_CODEGEN_END(DTO)
#endif // !_IMPORTLEAGALPERSETTING_DTO_