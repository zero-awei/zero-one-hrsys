#pragma once
#ifndef _QUALIFICATIONQUERY_H_
#define _QUALIFICATIONQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QualificationQuery :public PageQuery
{
	DTO_INIT(QualificationQuery, PageQuery);
	// 执业资格专业编码
	DTO_FIELD(String, pimqualmajorid);
	DTO_FIELD_INFO(pimqualmajorid) {
		info->description = ZH_WORDS_GETTER("archive.field.pimqualmajorid");
	}
	// 级别
	DTO_FIELD(String, qualevel);
	DTO_FIELD_INFO(qualevel) {
		info->description = ZH_WORDS_GETTER("archive.field.qualevel");
	}
	// 执业资格
	DTO_FIELD(String, pimqualmajorname);
	DTO_FIELD_INFO(pimqualmajorname) {
		info->description = ZH_WORDS_GETTER("archive.field.pimqualmajorname");
	}
	//专业
	DTO_FIELD(String, quamajor);
	DTO_FIELD_INFO(quamajor) {
		info->description = ZH_WORDS_GETTER("archive.field.quamajor");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
