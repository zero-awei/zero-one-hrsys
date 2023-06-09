#pragma once
#ifndef _CERTIFICATEDTO_H_
#define _CERTIFICATEDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个可修改岗位技能证书的传输对象
 */
class CertificateDTO : public oatpp::DTO
{
	DTO_INIT(CertificateDTO, DTO);
	// 排序号
	DTO_FIELD(UInt64, seialno);
	DTO_FIELD_INFO(seialno) {
		info->description = ZH_WORDS_GETTER("certificate.field.seialno");
	}
	// 岗位技能证书
	DTO_FIELD(String, pimqualtypename);
	DTO_FIELD_INFO(pimqualtypename) {
		info->description = ZH_WORDS_GETTER("certificate.field.pimqualtypename");
	}
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
