#pragma once

#ifndef _CREATE_NEW_CER_QUERY_
#define _CREATE_NEW_CER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
  证书管理-证书信息-新建证书--pine
*/
class CreateNewCerQuery : public PageQuery
{
	DTO_INIT(CreateNewCerQuery, PageQuery);
	// 员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygbh");
	}
	// 证书编号
	DTO_FIELD(String, zgzsbh);
	DTO_FIELD_INFO(zgzsbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zgzsbh");
	}
	// 一建配套B证编号
	DTO_FIELD(String, bcardNumber);
	DTO_FIELD_INFO(bcardNumber) {
		info->description = ZH_WORDS_GETTER("cermanage.field.bcardNumber");
	}
	// 证书名称(执业资格证书)
	DTO_FIELD(String, pimVocationalName);
	DTO_FIELD_INFO(pimVocationalName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimVocationalName");
	}
	// 证书类型
	DTO_FIELD(String, zslx);
	DTO_FIELD_INFO(zslx) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zslx");
	}
	// 签发日期
	DTO_FIELD(String, zghqrq);
	DTO_FIELD_INFO(zghqrq) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zghqrq");
	}
	// 签发机构
	DTO_FIELD(String, zgsydw);
	DTO_FIELD_INFO(zgsydw) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zgsydw");
	}
	// 注册单位
	DTO_FIELD(String, zcdw);
	DTO_FIELD_INFO(zcdw) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zcdw");
	}
	// 失效日期
	DTO_FIELD(String, sxrq);
	DTO_FIELD_INFO(sxrq) {
		info->description = ZH_WORDS_GETTER("cermanage.field.sxrq");
	}
	// 年审情况
	DTO_FIELD(String, nsqk);
	DTO_FIELD_INFO(nsqk) {
		info->description = ZH_WORDS_GETTER("cermanage.field.nsqk");
	}
	// 使用情况
	DTO_FIELD(String, syqk);
	DTO_FIELD_INFO(syqk) {
		info->description = ZH_WORDS_GETTER("cermanage.field.syqk");
	}
	// 变更情况
	DTO_FIELD(String, alteration);
	DTO_FIELD_INFO(alteration) {
		info->description = ZH_WORDS_GETTER("cermanage.field.alteration");
	}
	// 员工唯一标识
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimpersonid");
	}
	// 注册编号
	DTO_FIELD(String, regisnumber);
	DTO_FIELD_INFO(regisnumber) {
		info->description = ZH_WORDS_GETTER("cermanage.field.regisnumber");
	}
	// 社保缴纳单位
	DTO_FIELD(String, socsecpayunit);
	DTO_FIELD_INFO(socsecpayunit) {
		info->description = ZH_WORDS_GETTER("cermanage.field.socsecpayunit");
	}
	// 初始注册时间
	DTO_FIELD(String, cszcsj);
	DTO_FIELD_INFO(cszcsj) {
		info->description = ZH_WORDS_GETTER("cermanage.field.cszcsj");
	}
	// 续注册时间
	DTO_FIELD(String, xzcsj);
	DTO_FIELD_INFO(xzcsj) {
		info->description = ZH_WORDS_GETTER("cermanage.field.xzcsj");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CREATE_NEW_CER_QUERY_