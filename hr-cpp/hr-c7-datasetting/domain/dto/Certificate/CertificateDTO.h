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
	//员工编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("certificate.field.id"));
	//员工姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("certificate.field.name"));
	//员工状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("certificate.field.state"));
	//组织
	API_DTO_FIELD_DEFAULT(String, organization, ZH_WORDS_GETTER("certificate.field.organization"));
	//证书编号
	API_DTO_FIELD_DEFAULT(String, certificateNumber, ZH_WORDS_GETTER("certificate.field.certificateNumber"));
	//一建配套B证编号
	API_DTO_FIELD_DEFAULT(String, certificateNubmerB, ZH_WORDS_GETTER("certificate.field.certificateNubmerB"));
	//证书名称
	API_DTO_FIELD_DEFAULT(String, certificateName, ZH_WORDS_GETTER("certificate.field.certificateName"));
	//证书类型
	API_DTO_FIELD_DEFAULT(String, certificateType, ZH_WORDS_GETTER("certificate.field.certificateType"));
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