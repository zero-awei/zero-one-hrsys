#pragma once
/**
 * (证书管理-查询证书类型列表)--weixiaoman
 */
#ifndef _CERTIFICATETYPE_VO_
#define _CERTIFICATETYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/CertificateTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 证书类型显示JsonVO，用于响应给客户端的Json对象
 */
class CertificateTypeJsonVO : public JsonVO<CertificateTypeDTO::Wrapper> {
	DTO_INIT(CertificateTypeJsonVO, JsonVO<CertificateTypeDTO::Wrapper>);
};

/**
 * 证书类型显示JsonVO，用于响应给客户端的Json对象
 */
class CertificateTypePageJsonVO : public JsonVO<CertificateTypePageDTO::Wrapper> {
	DTO_INIT(CertificateTypePageJsonVO, JsonVO<CertificateTypePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_CERTIFICATETYPE_VO_