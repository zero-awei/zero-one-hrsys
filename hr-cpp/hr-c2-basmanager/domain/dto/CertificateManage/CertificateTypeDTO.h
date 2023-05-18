#pragma once
/**
*  人员信息查询，输入搜索框使用
*/
#ifndef _CERTIFICATETYPE_DTO_
#define _CERTIFICATETYPE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
* 证书类型查询传输对象
*/
class CertificateTypeDTO : public oatpp::DTO
{
	DTO_INIT(CertificateTypeDTO, DTO);
	//证书类型
	DTO_FIELD(String, certype);
	DTO_FIELD_INFO(certype) {
		info->description = ZH_WORDS_GETTER("EmpInfo.field.name");
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