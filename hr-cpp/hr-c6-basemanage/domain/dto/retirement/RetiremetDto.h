#pragma once
#ifndef _RETIREMETDTO_H_
#define _RETIREMETDTO_H_


#include "stdafx.h"
#include "../../GlobalInclude.h"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
class RetirementDTO : public oatpp::DTO
{
	//初始化
	DTO_INIT(RetirementDTO, DTO);
	// 员工id1
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.number");
	}
	DTO_FIELD(String, name);
	// 查询的第二个参数，员工姓名2
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("retirement_gan.query.name");
	}
	DTO_FIELD(String, sex);
	// 员工性别3
	DTO_FIELD_INFO(sex) {
		info->description = "xing bie ";
	}
	DTO_FIELD(String, age);
	// 员工年龄4
	DTO_FIELD_INFO(age) {
		info->description = "nian ling ";
	}
	DTO_FIELD(String, mailing_address);
	// 员工通讯地址5
	DTO_FIELD_INFO(mailing_address) {
		info->description = "di zhi ";
	}
	DTO_FIELD(String, retire_address);
	// 员工退休地6
	DTO_FIELD_INFO(retire_address) {
		info->description = "tui xiu di ";
	}
	DTO_FIELD(String, Family_contact);
	// 员工家庭联系人7
	DTO_FIELD_INFO(Family_contact) {
		info->description = "jia ting lian xi ren ";
	}
	DTO_FIELD(String, Family_contact_tel);
	// 员工家庭联系人电话
	DTO_FIELD_INFO(Family_contact_tel) {
		info->description = "jia ting lian xi ren dian hua";
	}
	DTO_FIELD(String, organization);
	// 组织8
	DTO_FIELD_INFO(organization) {
		info->description = "zu zhi";
	}
	DTO_FIELD(String, department);
	// 部门9
	DTO_FIELD_INFO(department) {
		info->description = "bu men";
	}
	DTO_FIELD(String, rank);
	// 职级10
	DTO_FIELD_INFO(rank) {
		info->description = "zhi ji";
	}
	DTO_FIELD(String, before_retire_rank);
	// 退休前职务11
	DTO_FIELD_INFO(before_retire_rank) {
		info->description = "tui xiu qian zhi wu";
	}
	DTO_FIELD(String, before_retire_post);
	// 退休前岗位12
	DTO_FIELD_INFO(before_retire_post) {
		info->description = "tui xiu qian gang wei";
	}
	DTO_FIELD(String, retire_time);
	// 退休时间13
	DTO_FIELD_INFO(retire_time) {
		info->description = "tui xiu shi jian";
	}
	DTO_FIELD(String, read_retire_time);
	// 实际退休时间14
	DTO_FIELD_INFO(read_retire_time) {
		info->description = "shi ji tui xiu shi jian";
	}
	DTO_FIELD(String, tel);
	// 手机号码15
	DTO_FIELD_INFO(tel) {
		info->description = "dian hua hao ma";
	}
	DTO_FIELD(String, Approved_pension_amount);
	// 审批的养老金额16
	DTO_FIELD_INFO(Approved_pension_amount) {
		info->description = "shen pi yang lao jin e";
	}
};

/**
 * 示例分页传输对象
 */
class RetirementPageDTO : public PageDTO<RetirementDTO::Wrapper>
{
	DTO_INIT(RetirementPageDTO, PageDTO<RetirementDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RETIREMETDTO_H_
