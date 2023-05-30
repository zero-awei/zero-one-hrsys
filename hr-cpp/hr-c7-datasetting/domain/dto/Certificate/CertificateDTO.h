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
	CertificateDTO(String seialno, String pimqualtypename) :seialno(seialno), pimqualtypename(pimqualtypename) {};
	DTO_INIT(CertificateDTO, DTO);
	//排序号
	API_DTO_FIELD_DEFAULT(String, seialno, ZH_WORDS_GETTER("certificate.field.seialno"));
	//岗位技能证书
	API_DTO_FIELD_DEFAULT(String, pimqualtypename, ZH_WORDS_GETTER("certificate.field.pimqualtypename"));
	
	
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