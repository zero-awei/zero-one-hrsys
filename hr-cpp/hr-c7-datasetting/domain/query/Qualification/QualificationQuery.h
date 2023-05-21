#pragma once
#ifndef _QULIFICATIONQUERY_H_
#define _QULIFICATIONQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QualificationQuery :public PageQuery
{
	DTO_INIT(QualificationQuery, PageQuery);
	//职业资格名称
	API_DTO_FIELD_DEFAULT(String, QualificationName, ZH_WORDS_GETTER("qualification.field.qualificationName"));
};

#include OATPP_CODEGEN_END(DTO)
#endif