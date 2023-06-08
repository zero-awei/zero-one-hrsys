#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2023/05/20 21:00:29
*/
#ifndef _EMPLOYEELANGUAGEEXPORT_QUERY_
#define _EMPLOYEELANGUAGEEXPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EmployeeLanguageExportQuery : public PageQuery
{
	DTO_INIT(EmployeeLanguageExportQuery, DTO);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	DTO_FIELD(String, id);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEELANGUAGEEXPORT_QUERY_