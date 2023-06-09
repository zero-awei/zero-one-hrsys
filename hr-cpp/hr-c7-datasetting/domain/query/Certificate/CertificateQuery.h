#pragma once
#ifndef _CERTIFICATEQUERY_H_
#define _CERTIFICATEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例岗位技能证书查询对象
 */
class CertificateQuery :public PageQuery
{
	DTO_INIT(CertificateQuery, PageQuery);
	// 排序号
	DTO_FIELD(UInt64, seialno);
	DTO_FIELD_INFO(seialno) {
		info->description = ZH_WORDS_GETTER("certificate.field.seialno");
	}
	// 档案室名称
	DTO_FIELD(String, pimqualtypename);
	DTO_FIELD_INFO(pimqualtypename) {
		info->description = ZH_WORDS_GETTER("certificate.field.pimqualtypename");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
