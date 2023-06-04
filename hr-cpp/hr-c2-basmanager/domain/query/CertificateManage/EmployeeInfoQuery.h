#pragma once
#ifndef _EMPLOYEEINFO_QUERY_
#define _EMPLOYEEINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 人员信息分页查询对象--(证书管理-分页查询员工信息列表)--weixiaoman
 */

class EmployeeInfoQuery : public PageQuery
{
	DTO_INIT(EmployeeInfoQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEEINFO_QUERY_