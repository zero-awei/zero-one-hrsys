#pragma once
/**
* 分页查询证书列表--(证书管理-分页查询证书列表)--pine
 */
#ifndef _CHECK_CER_QUERY_
#define _CHECK_CER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CheckCerListQuery : public PageQuery
{
	DTO_INIT(CheckCerListQuery, PageQuery);
	// 员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygbh");
	}
	// 模糊查找(证书和人员姓名)
	DTO_FIELD(String, nameOfPAndV);
	DTO_FIELD_INFO(nameOfPAndV) {
		info->description = ZH_WORDS_GETTER("cermanage.field.nameOfPAndV");
	}
	// 员工姓名
	DTO_FIELD(String, pimperSonName);
	DTO_FIELD_INFO(pimperSonName) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimperSonName");
	}
	// 员工状态 
	DTO_FIELD(String, ygzt);
	DTO_FIELD_INFO(ygzt) {
		info->description = ZH_WORDS_GETTER("cermanage.field.ygzt");
	}
	// 组织
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("cermanage.field.zz");
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
	// 证书名称
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
	// 发证有效期
	DTO_FIELD(String, fzyxq);
	DTO_FIELD_INFO(fzyxq) {
		info->description = ZH_WORDS_GETTER("cermanage.field.fzyxq");
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
	// 证书唯一标识
	DTO_FIELD(String, pimvocationalid);
	DTO_FIELD_INFO(pimvocationalid) {
		info->description = ZH_WORDS_GETTER("cermanage.field.pimvocationalid");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHECK_CER_QUERY_