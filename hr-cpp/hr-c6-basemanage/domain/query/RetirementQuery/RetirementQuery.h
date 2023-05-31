#pragma once

#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#ifndef _RETIREMENTQUERY_H_
#define _RETIREMENTQUERY_H_


#include OATPP_CODEGEN_BEGIN(DTO)


class RetirementQuery_gan :public PageQuery {
	DTO_INIT(RetirementQuery_gan, PageQuery);
	// 查询的第一个参数，员工编号
	// 员工id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.number");
	}
	DTO_FIELD(String, name);
	// 查询的第二个参数，员工姓名
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.name");
	}
	DTO_FIELD(String, sex);
	// 员工性别
	DTO_FIELD_INFO(sex) {
		info->description = "xing bie ";
	}
	DTO_FIELD(String, age);
	// 员工年龄
	DTO_FIELD_INFO(age) {
		info->description = "nian ling ";
	}
	DTO_FIELD(String, mailing_address);
	// 员工通讯地址
	DTO_FIELD_INFO(mailing_address) {
		info->description = "di zhi ";
	}
	DTO_FIELD(String, retire_address);
	// 员工退休地
	DTO_FIELD_INFO(retire_address) {
		info->description = "tui xiu di ";
	}
	DTO_FIELD(String, Family_contact);
	// 员工家庭联系人
	DTO_FIELD_INFO(Family_contact) {
		info->description = "jia ting lian xi ren ";
	}
	DTO_FIELD(String, organization);
	// 组织
	DTO_FIELD_INFO(organization) {
		info->description = "zu zhi";
	}
	DTO_FIELD(String, department);
	// 部门
	DTO_FIELD_INFO(department) {
		info->description = "bu men";
	}
	DTO_FIELD(String, rank);
	// 职级
	DTO_FIELD_INFO(rank) {
		info->description = "zhi ji";
	}
	DTO_FIELD(String, before_retire_rank);
	// 退休前职务
	DTO_FIELD_INFO(before_retire_rank) {
		info->description = "tui xiu qian zhi wu";
	}
	DTO_FIELD(String, before_retire_post);
	// 退休前岗位
	DTO_FIELD_INFO(before_retire_post) {
		info->description = "tui xiu qian gang wei";
	}
	DTO_FIELD(String, retire_time);
	// 退休时间
	DTO_FIELD_INFO(retire_time) {
		info->description = "tui xiu shi jian";
	}
	DTO_FIELD(String, read_retire_time);
	// 实际退休时间
	DTO_FIELD_INFO(read_retire_time) {
		info->description = "shi ji tui xiu shi jian";
	}
	DTO_FIELD(String, tel);
	// 手机号码
	DTO_FIELD_INFO(tel) {
		info->description = "dian hua hao ma";
	}
	DTO_FIELD(String, Approved_pension_amount);
	// 审批的养老金额
	DTO_FIELD_INFO(Approved_pension_amount) {
		info->description = "shen pi yang lao jin e";
	}
};

#include OATPP_CODEGEN_END(DTO)



#endif // !_RETIREMENTQUERY_H_
