#pragma once
#ifndef _EXPORT_RETIREES_DTO_
#define _EXPORT_RETIREES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportRetireesDTO : public oatpp::DTO
{
public:
	//无参构造
	ExportRetireesDTO() {};
	//有参构造
	//ExportRetireesDTO(UInt64 id, String name, Int32 age, String sex) {};
	ExportRetireesDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(ExportRetireesDTO, DTO);
	// 编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名A
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

class ExportRetireesPageDTO : public PageDTO<ExportRetireesDTO::Wrapper>
{
	DTO_INIT(ExportRetireesPageDTO, PageDTO<ExportRetireesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORT_RETIREES_DTO_