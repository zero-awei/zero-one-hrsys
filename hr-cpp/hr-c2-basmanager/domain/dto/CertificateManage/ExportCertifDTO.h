#pragma once
/*
（证书管理-证书信息-导出证书（导出本页在前端完成））--洛洛
*/
#ifndef _EXPORTCERTIF_DTO_
#define _EXPORTCERTIF_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ExportCertifDTO : public oatpp::DTO
{
	DTO_INIT(ExportCertifDTO, DTO);
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
class ExportCertifPageDTO : public PageDTO<ExportCertifDTO::Wrapper>
{
	DTO_INIT(ExportCertifPageDTO, PageDTO<ExportCertifDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTCERTIF_DTO_