#pragma once
#ifndef _CERTIFICATE_INFORMATION_VO_H_
#define _CERTIFICATE_INFORMATION_VO_H_
#include "../../GlobalInclude.h"
#include "../../dto/certificate-information/CertificateInformationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class CertificateInformationPageJsonVO : public JsonVO<CertificateInformationPageDTO::Wrapper> {
	DTO_INIT(CertificateInformationPageJsonVO, JsonVO<CertificateInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 
