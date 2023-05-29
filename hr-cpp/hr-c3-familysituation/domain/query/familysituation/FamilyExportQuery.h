#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2023/05/20 21:00:29
*/
#ifndef _FAMILYEXPORT_QUERY_
#define _FAMILYEXPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class FamilyExportQuery : public PageQuery
{
	DTO_INIT(FamilyExportQuery, DTO);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	DTO_FIELD(String, id);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FAMILYEXPORT_QUERY_
