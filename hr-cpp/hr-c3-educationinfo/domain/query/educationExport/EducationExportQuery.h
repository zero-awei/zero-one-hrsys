#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2023/05/20 21:00:29
*/
#ifndef _EDUCATIONEXPORT_QUERY_
#define _EDUCATIONEXPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EducationExportQuery : public PageQuery
{
	DTO_INIT(EducationExportQuery, DTO);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	DTO_FIELD(String, id);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONEXPORT_QUERY_
