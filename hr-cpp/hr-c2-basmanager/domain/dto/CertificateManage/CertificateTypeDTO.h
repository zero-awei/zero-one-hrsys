#pragma once
#ifndef _CERTIFICATETYPE_DTO_
#define _CERTIFICATETYPE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
* 证书类型查询传输对象--(证书管理-查询证书类型列表)--weixiaoman
*/
class CertificateTypeDTO : public oatpp::DTO
{
	DTO_INIT(CertificateTypeDTO, DTO);
	//证书类型
	DTO_FIELD(String, certype);
	DTO_FIELD_INFO(certype) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.name");
	}
	//证书唯一标识
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.id");
	}
};


/**
 * 证书类型分页传输对象
 */
class  CertificateTypePageDTO : public PageDTO< CertificateTypeDTO::Wrapper>
{
	DTO_INIT(CertificateTypePageDTO, PageDTO< CertificateTypeDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CERTIFICATETYPE_DTO_