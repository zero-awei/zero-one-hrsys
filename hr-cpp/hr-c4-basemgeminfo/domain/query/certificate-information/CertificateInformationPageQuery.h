#pragma once
#ifndef _CERTIFICATE_INFORMATION_PAGEQUERY_H_
#define _CERTIFICATE_INFORMATION_PAGEQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class CertificateInformationPageQuery : public PageQuery
{
	DTO_INIT(CertificateInformationPageQuery, PageQuery);
	////zgzsbh: 证书编号
	//DTO_FIELD(String, zgzsbh);
	//DTO_FIELD_INFO(zgzsbh) {
	//	info->description = ZH_WORDS_GETTER("sample.field.zgzsbh");
	//}
	//pimvocationalname: 证书名称
	DTO_FIELD(String, pimvocationalname);
	DTO_FIELD_INFO(pimvocationalname) {
		info->description = ZH_WORDS_GETTER("sample.field.pimvocationalname");
	}
	//// zslx: 证书类型
	//DTO_FIELD(String, zslx);
	//DTO_FIELD_INFO(zslx) {
	//	info->description = ZH_WORDS_GETTER("sample.field.zslx");
	//}
	//// zghqrq: 签发日期
	//DTO_FIELD(String, zghqrq);
	//DTO_FIELD_INFO(zghqrq) {
	//	info->description = ZH_WORDS_GETTER("sample.field.zghqrq");
	//}
	//// zgsydw: 签发机构
	//DTO_FIELD(String, zgsydw);
	//DTO_FIELD_INFO(zgsydw) {
	//	info->description = ZH_WORDS_GETTER("sample.field.zgsydw");
	//}
	//// fzyxq: 发证有效期
	//DTO_FIELD(String, fzyxq);
	//DTO_FIELD_INFO(fzyxq) {
	//	info->description = ZH_WORDS_GETTER("sample.field.fzyxq");
	//}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // 