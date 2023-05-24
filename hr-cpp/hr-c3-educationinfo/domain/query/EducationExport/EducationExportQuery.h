/*
 Copyright Zero One Star. All rights reserved.

 @Author: Chen J
 @Date: 2023/05/20 21:00:29
*/
#ifndef _EDUCATIONEXPORTQUERY_H_
#define _EDUCATIONEXPORTQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EducationExportQuery : public oatpp::DTO
{
	DTO_INIT(EducationExportQuery, DTO);
	DTO_FIELD_INFO(rows) {
		info->description = ZH_WORDS_GETTER("export.rows");
	}
	DTO_FIELD(UInt8, rows);
	DTO_FIELD_INFO(sequence) {
		info->description = ZH_WORDS_GETTER("export.sequence");
	}
	DTO_FIELD(String, sequence);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EDUCATIONEXPORTQUERY_H_#pragma once
