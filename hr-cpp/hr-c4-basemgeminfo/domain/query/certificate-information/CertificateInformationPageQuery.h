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
	// 员工编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	}
	// 员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("sample.field.name");
	}
	// 组织 ormorgname
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.ormorgname");
	}
	// 员工状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("jobtitleinformation.field.state");
	}
	//zgzsbh: 证书编号
	DTO_FIELD(String, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("sample.field.zgzsbh");
	}
	//pimvocationalname: 证书名称
	DTO_FIELD(String, pimvocationalname);
	DTO_FIELD_INFO(pimvocationalname) {
		info->description = ZH_WORDS_GETTER("sample.field.pimvocationalname");
	}
	// zslx: 证书类型
	DTO_FIELD(String, zslx);
	DTO_FIELD_INFO(zslx) {
		info->description = ZH_WORDS_GETTER("sample.field.zslx");
	}
	// zghqrq: 签发日期
	DTO_FIELD(String, zghqrq);
	DTO_FIELD_INFO(zghqrq) {
		info->description = ZH_WORDS_GETTER("sample.field.zghqrq");
	}
	// zgsydw: 签发机构
	DTO_FIELD(String, zgsydw);
	DTO_FIELD_INFO(zgsydw) {
		info->description = ZH_WORDS_GETTER("sample.field.zgsydw");
	}
	// fzyxq: 发证有效期
	DTO_FIELD(String, fzyxq);
	DTO_FIELD_INFO(fzyxq) {
		info->description = ZH_WORDS_GETTER("sample.field.fzyxq");
	}
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // 