#pragma once
#ifndef _QUALIFICATIONQUERY_H_
#define _QUALIFICATIONQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QualificationQuery :public PageQuery
{
	DTO_INIT(QualificationQuery, PageQuery);
	//执业资格名称
	API_DTO_FIELD_DEFAULT(String, QualificationName, ZH_WORDS_GETTER("qualification.field.qualificationName"));
	//岗位类型
	API_DTO_FIELD_DEFAULT(String, practicingQualification, ZH_WORDS_GETTER("qualification.field.practicingQualification"));
};

#include OATPP_CODEGEN_END(DTO)
#endif