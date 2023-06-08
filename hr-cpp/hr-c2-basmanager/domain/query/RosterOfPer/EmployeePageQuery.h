#pragma once
/*
（人员花名册-人员花名册-分页查询员工列表）--洛洛
*/
#ifndef _EMPLOYEE_PAGE_QUERY_ 
#define _EMPLOYEE_PAGE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EmployeePageQuery : public PageQuery
{
	DTO_INIT(EmployeePageQuery, PageQuery);
	// 员工姓名和员工编号 模糊查询
	DTO_FIELD(String, idAndName);
	DTO_FIELD_INFO(idAndName) {
		info->description = ZH_WORDS_GETTER("employee.field.idAndName");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEE_PAGE_QUERY_