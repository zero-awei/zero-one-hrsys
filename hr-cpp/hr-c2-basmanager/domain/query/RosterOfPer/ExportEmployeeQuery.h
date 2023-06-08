#pragma once
/*
（人员花名册-人员花名册-导出员工（导出本页在前端完成））--luoluo
*/
#ifndef _EXPORTEMPLOYEE_QUERY_
#define _EXPORTEMPLOYEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ExportEmployeeQuery : public PageQuery
{
	DTO_INIT(ExportEmployeeQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("sample.field.sex");
	}
	// 年龄
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("sample.field.age");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORTEMPLOYEE_QUERY_