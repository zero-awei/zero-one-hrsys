#pragma once
#ifndef _CERTIFICATE_INFO_VO_
#define _CERTIFICATE_INFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/SpercificCertificateDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class SpercificCertificateJsonVO : public JsonVO<SpercificCertificateDTO::Wrapper>
{
	DTO_INIT(SpercificCertificateJsonVO, JsonVO<SpercificCertificateDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_CERTIFICATE_INFO_VO_