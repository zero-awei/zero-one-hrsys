#pragma once
#ifndef _PROBATIONARY_EMPLOYEE_QUERY_
#define _PROBATIONARY_EMPLOYEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 人员花名册 - 试用人员Query实现 - 楚孟献
 */
class ProbationaryEmployeeQuery : public PageQuery
{
	DTO_INIT(ProbationaryEmployeeQuery, PageQuery);
	// id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
