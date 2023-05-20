#pragma once
#ifndef _CERTIFICATEVO_H_
#define _CERTIFICATEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Certificate/CertificateDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个证书信息显示JsonVO对象，用于响应给客户端
 */

class CertificateJsonVO : public JsonVO<CertificateDTO::Wrapper>
{
	DTO_INIT(CertificateJsonVO, JsonVO<CertificateDTO::Wrapper>);
};

/**
 * 定义一个证书信息分页显示JsonVO对象，用于响应给客户端
 */
class CertificatePageJsonVO : public JsonVO<CertificatePageDTO::Wrapper>
{
	DTO_INIT(CertificatePageJsonVO, JsonVO<CertificatePageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif
 