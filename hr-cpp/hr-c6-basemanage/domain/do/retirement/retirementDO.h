#pragma once
#ifndef _RETIREMENTDO_H_
#define _RETIREMENTDO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class retirementDO
{
	// 员工编号1
	CC_SYNTHESIZE(string, id, Id);
	// 员工姓名2
	CC_SYNTHESIZE(string, name, Name);
	// 员工性别3
	CC_SYNTHESIZE(string, sex, Sex);
	// 员工年龄4
	CC_SYNTHESIZE(string, age, Age);
	// 员工通讯地址5
	CC_SYNTHESIZE(string, mailing_address, Mailing_address);
	// 员工退休地址6
	CC_SYNTHESIZE(string, retire_address, Retire_address);
	// 员工家庭联系人7
	CC_SYNTHESIZE(string, Family_contact, Family_Contact);
	// 员工家庭联系人电话8
	CC_SYNTHESIZE(string, Family_contact_tel, Family_Contact_tel);
	// 员工组织9
	CC_SYNTHESIZE(string, organization, Organization);
	// 员工部门10
	CC_SYNTHESIZE(string, department, Department);
	// 员工职级11
	CC_SYNTHESIZE(string, rank, Rank);
	// 员工退休前职务12
	CC_SYNTHESIZE(string, before_retire_rank, Before_retire_rank);
	// 员工退休前岗位13
	CC_SYNTHESIZE(string, before_retire_post, Before_retire_post);
	// 员工退休时间14
	CC_SYNTHESIZE(string, retire_time, Retire_time);
	// 员工实际退休时间15
	CC_SYNTHESIZE(string, read_retire_time, Read_retire_time);
	// 员工电话16
	CC_SYNTHESIZE(string, tel, Tel);
	// 员工养老金额17
	CC_SYNTHESIZE(string, Approved_pension_amount, Approved_Pension_amount);
public:
	retirementDO() {
	}
};

#endif // !_RETIREMENTDO_H_
