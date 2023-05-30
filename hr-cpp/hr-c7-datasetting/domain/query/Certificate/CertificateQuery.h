#pragma once
#ifndef _CERTIFICATEQUERY_H_
#define _CERTIFICATEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CertificateQuery :public PageQuery
{
	DTO_INIT(CertificateQuery, PageQuery);
	//排序号
	API_DTO_FIELD_DEFAULT(String, seialno, ZH_WORDS_GETTER("certificate.field.seialno"));
	//岗位技能证书
	API_DTO_FIELD_DEFAULT(String, pimqualtypename, ZH_WORDS_GETTER("certificate.field.pimqualtypename"));
};

#include OATPP_CODEGEN_END(DTO)
#endif