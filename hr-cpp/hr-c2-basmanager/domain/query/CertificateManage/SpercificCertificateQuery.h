#ifndef _SPERCIFIC_CERTIFIDATE_QUERY_
#define _SPERCIFIC_CERTIFIDATE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SpercificCertificateQuery : public PageQuery
{
	DTO_INIT(SpercificCertificateQuery, PageQuery);
	// ±àºÅ
	DTO_FIELD(String, PIMVOCATIONALID);
	DTO_FIELD_INFO(PIMVOCATIONALID) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.PIMVOCATIONALID");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
