/**
 *  证书管理 —— 证书信息 —— 查询、更新指定证书 —— 楚孟献
 */
#ifndef _SPERTIFIC_CERTIFICATE_DTO_
#define _SPERTIFIC_CERTIFICATE_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class SpercificCertificateDTO : public oatpp::DTO
{

	DTO_INIT(SpercificCertificateDTO, DTO);
	
	// 执（职）业资格信息标识
	DTO_FIELD(String, PIMVOCATIONALID);
	DTO_FIELD_INFO(PIMVOCATIONALID) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.PIMVOCATIONALID");
	}
	// 姓名  required
	DTO_FIELD(String, pimperSonName);
	DTO_FIELD_INFO(pimperSonName) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.pimperSonName");
	}
	// 证书编号  required
	DTO_FIELD(String, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zgzsbh");
	}
	// 证书类型  required
	DTO_FIELD(String, zslx);
	DTO_FIELD_INFO(zslx) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zslx");
	}
	// 证书名称
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.pimVocationalName");
	}
	// 签发机构
	DTO_FIELD(String, zgsydw);
	DTO_FIELD_INFO(zgsydw) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zgsydw");
	}
	// 注册编号
	DTO_FIELD(String, REGISNUMBER);
	DTO_FIELD_INFO(REGISNUMBER) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.REGISNUMBER");
	}
	// 注册单位
	DTO_FIELD(String, zcdw);
	DTO_FIELD_INFO(zcdw) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zcdw");
	}
	// 社保缴纳单位
	DTO_FIELD(String, SOCSECPAYUNIT);
	DTO_FIELD_INFO(SOCSECPAYUNIT) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.SOCSECPAYUNIT");
	}
	// 一建配套B证编号
	DTO_FIELD(String, bcardNumber);
	DTO_FIELD_INFO(bcardNumber) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.bcardNumber");
	}
	
	// 证书获得情况

	// 签发日期  required
	DTO_FIELD(String, zghqrq);
	DTO_FIELD_INFO(zghqrq) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.zghqrq");
	}
	// 初始注册时间
	DTO_FIELD(String, CSZCSJ);
	DTO_FIELD_INFO(CSZCSJ) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.CSZCSJ");
	}
	// 续注册时间
	DTO_FIELD(String, XZCSJ);
	DTO_FIELD_INFO(XZCSJ) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.XZCSJ");
	}
	// 失效日期
	DTO_FIELD(String, sxrq);
	DTO_FIELD_INFO(sxrq) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.sxrq");
	}
	// 年审情况
	DTO_FIELD(String, NSQK);
	DTO_FIELD_INFO(NSQK) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.NSQK");
	}
	// 使用情况
	DTO_FIELD(String, SYQK);
	DTO_FIELD_INFO(SYQK) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.SYQK");
	}
	// 变更情况
	DTO_FIELD(String, ALTERATION);
	DTO_FIELD_INFO(ALTERATION) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.ALTERATION");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
