#pragma once
/*
人员花名册-离退休人员-分页查询员工列表--pine
*/
#ifndef _CHECK_RETIRES_DTO_
#define _CHECK_RETIRES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CheckRetiresListDTO : public oatpp::DTO
{
public:
	//无参构造
	CheckRetiresListDTO() {};
	//有参构造
	//CheckRetiresListDTO(UInt64 id, String name, Int32 age, String sex) {};
	//CheckRetiresListDTO(UInt64 id, String name) :id(id), name(name) {};
	DTO_INIT(CheckRetiresListDTO, DTO);
	// 员工编号
	DTO_FIELD(String, ygbh);
	DTO_FIELD_INFO(ygbh) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.ygbh");
	}
	// 唯一标识
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.id");
	}
	// 员工编号+姓名（模糊查询）
	DTO_FIELD(String, idAndName);
	DTO_FIELD_INFO(idAndName) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.idAndName");
	}
	// 员工姓名
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.pimpersonname");
	}
	// 性别
	DTO_FIELD(String, xb);
	DTO_FIELD_INFO(xb) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.xb");
	}
	// 年龄
	DTO_FIELD(String, nj);
	DTO_FIELD_INFO(nj) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.nj");
	}
	// 通讯地址
	DTO_FIELD(String, postaladdress);
	DTO_FIELD_INFO(postaladdress) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.postaladdress");
	}
	// 退休地
	DTO_FIELD(String, retiPlace);
	DTO_FIELD_INFO(retiPlace) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.retiPlace");
	}
	// 家庭联系人
	DTO_FIELD(String, jtlxr);
	DTO_FIELD_INFO(jtlxr) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.jtlxr");
	}
	// 家庭联系人电话
	DTO_FIELD(String, jtlxrdh);
	DTO_FIELD_INFO(jtlxrdh) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.jtlxrdh");
	}
	// 组织
	DTO_FIELD(String, zz);
	DTO_FIELD_INFO(zz) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.zz");
	}
	// 部门
	DTO_FIELD(String, bm);
	DTO_FIELD_INFO(bm) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.bm");
	}
	// 职级
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.rank");
	}
	// 退休前职务
	DTO_FIELD(String, yzw);
	DTO_FIELD_INFO(yzw) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.yzw");
	}
	// 退休前岗位
	DTO_FIELD(String, ygw);
	DTO_FIELD_INFO(ygw) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.ygw");
	}
	// 退休时间
	DTO_FIELD(String, txdq);
	DTO_FIELD_INFO(txdq) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.txdq");
	}
	// 实际退休时间
	DTO_FIELD(String, sjtxrq);
	DTO_FIELD_INFO(sjtxrq) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.sjtxrq");
	}
	// 手机号码
	DTO_FIELD(String, lxdh);
	DTO_FIELD_INFO(lxdh) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.lxdh");
	}
	// 审批的养老金额
	DTO_FIELD(String, spdylje);
	DTO_FIELD_INFO(spdylje) {
		info->description = ZH_WORDS_GETTER("rosterofper.field.spdylje");
	}
};

class CheckRetiresListPageDTO : public PageDTO<CheckRetiresListDTO::Wrapper>
{
	DTO_INIT(CheckRetiresListPageDTO, PageDTO<CheckRetiresListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 