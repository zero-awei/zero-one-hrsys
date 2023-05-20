#pragma once
#ifndef _CERTIFICATEQUERY_H_
#define _CERTIFICATEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CertificateQuery :public PageQuery
{
	DTO_INIT(CertificateQuery, PageQuery);
	//¸ÚÎ»Ö¤Êé
	API_DTO_FIELD_DEFAULT(String, certificateName, ZH_WORDS_GETTER("certificate.field.certificateName"));
};

#include OATPP_CODEGEN_END(DTO)
#endif