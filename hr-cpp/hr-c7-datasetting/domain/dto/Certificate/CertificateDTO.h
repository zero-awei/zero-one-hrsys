#pragma once
#ifndef _CERTIFICATEDTO_H_
#define _CERTIFICATEDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
  证书查询传输数据类型
*/

class CertificateDTO : public oatpp::DTO
{
public:
	CertificateDTO(){};
	DTO_INIT(CertificateDTO, DTO);
	//排序号
	API_DTO_FIELD_DEFAULT(String, certificateId, ZH_WORDS_GETTER("certificate.field.id"));
	//岗位证书
	API_DTO_FIELD_DEFAULT(String, certificateName, ZH_WORDS_GETTER("certificate.field.certificateName"));
	
	
};
/*
  证书查询分页传输数据类型
*/
class CertificatePageDTO : public PageDTO<CertificateDTO::Wrapper>
{
	DTO_INIT(CertificatePageDTO, PageDTO<CertificateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //!_CERTIFICATEDTO_H_