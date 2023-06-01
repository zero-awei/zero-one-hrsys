#pragma once
#ifndef _CERTIFICATETYPDE_QUERY_
#define _CERTIFICATETYPDE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 证书类型分页查询对象--(证书管理-查询证书类型列表)--weixiaoman
 */
class CertificateTypeQuery : public PageQuery
{
	DTO_INIT(CertificateTypeQuery, PageQuery);
	// 证书类型名称
	DTO_FIELD(String, certype);
	DTO_FIELD_INFO(certype) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.certype");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CERTIFICATETYPDE_QUERY_