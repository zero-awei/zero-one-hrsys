#pragma once
#ifndef _RETIREMENTDO_H_
#define _RETIREMENTDO_H_
#include "../DoInclude.h"
#include "../hr-sample/Macros.h"

/**
 * 示例数据库实体类
 */
class retirementDO
{
	// 员工编号
	CC_SYNTHESIZE(string, id, Id);
	// 员工姓名
	CC_SYNTHESIZE(string, name, Name);
	// 员工性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 员工年龄
	CC_SYNTHESIZE(string, age, Age);
	// 员工通讯地址
	CC_SYNTHESIZE(string, mailing_address, Mailing_address);
	// 员工退休地址
	CC_SYNTHESIZE(string, retire_address, Retire_address);
	// 员工家庭联系人
	CC_SYNTHESIZE(string, Family_contact, Family_Contact);
	// 员工组织
	CC_SYNTHESIZE(string, organization, Organization);
	// 员工部门
	CC_SYNTHESIZE(string, department, Department);
	// 员工职级
	CC_SYNTHESIZE(string, rank, Rank);
	// 员工退休前职务
	CC_SYNTHESIZE(string, before_retire_rank, Before_retire_rank);
	// 员工退休前岗位
	CC_SYNTHESIZE(string, before_retire_post, Before_retire_post);
	// 员工退休时间
	CC_SYNTHESIZE(string, retire_time, Retire_time);
	// 员工实际退休时间
	CC_SYNTHESIZE(string, read_retire_time, Read_retire_time);
	// 员工电话
	CC_SYNTHESIZE(string, tel, Tel);
	// 员工养老金额
	CC_SYNTHESIZE(string, Approved_pension_amount, Approved_Pension_amount);
public:
	retirementDO() {
	}
};

#endif // !_RETIREMENTDO_H_
