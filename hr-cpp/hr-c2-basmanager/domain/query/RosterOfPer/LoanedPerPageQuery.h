#pragma once
/*
（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
*/
#ifndef _LOANEDPERPAGE_QUERY_
#define _LOANEDPERPAGE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class LoanedPerPageQuery : public PageQuery
{
	DTO_INIT(LoanedPerPageQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	//// 年龄
	//DTO_FIELD(UInt32, age);
	//DTO_FIELD_INFO(age) {
	//	info->description = ZH_WORDS_GETTER("sample.field.age");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LOANEDPERPAGE_QUERY_