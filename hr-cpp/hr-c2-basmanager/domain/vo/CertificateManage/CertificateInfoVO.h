#ifndef _CERTIFICATE_INFO_VO_
#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/CertificateInfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class CertificateInfoJsonVO : public JsonVO<CertificateInfoDTO::Wrapper>
{
	DTO_INIT(CertificateInfoJsonVO, JsonVO<CertificateInfoDTO::Wrapper>);
};

/**
 * 离职员工分页传输对象
 */
class CertificateInfoPageJsonVO : public JsonVO<CertificateInfoPageDTO::Wrapper>
{
	DTO_INIT(CertificateInfoPageJsonVO, JsonVO<CertificateInfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 
