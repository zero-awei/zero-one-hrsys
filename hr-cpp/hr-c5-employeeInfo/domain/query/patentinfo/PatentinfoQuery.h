#pragma once
#ifndef _PAPER_QUERY_
#define _PAPER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * ר����Ϣ��ѯ����
 */
class PatentinfoQuery : public PageQuery
{
	DTO_INIT(PatentinfoQuery, PageQuery);

	// ר����Ϣ����
	DTO_FIELD(String, pimpatentid);
	DTO_FIELD_INFO(pimpatentid) {
		info->description = ZH_WORDS_GETTER("patentInformation.field.pimpatentid");
	}



};



#include OATPP_CODEGEN_END(DTO)
#endif