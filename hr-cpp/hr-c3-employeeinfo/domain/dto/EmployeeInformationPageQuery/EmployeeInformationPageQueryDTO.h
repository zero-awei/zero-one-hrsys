#pragma once

#ifndef _EMPLOYEE_INFOMATION_DTO_
#define _EMPLOYEE_INFOMATION_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 传输对象
 */
class EmployeeInformationDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeInformationDTO, DTO);
	
	//人员信息标识
	DTO_FIELD(String, personId);
	DTO_FIELD_INFO(personId) {
		info->description = ZH_WORDS_GETTER("employee.field.personId");
	}
	//建立人
	DTO_FIELD(String, createMan);
	DTO_FIELD_INFO(createMan) {
		info->description = ZH_WORDS_GETTER("employee.field.createMan");
	}
	//建立时间
	DTO_FIELD(String, createDate);
	DTO_FIELD_INFO(createDate) {
		info->description = ZH_WORDS_GETTER("employee.field.createDate");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("employee.field.name");
	}
	//// 性别
	//DTO_FIELD(String, sex);
	//DTO_FIELD_INFO(sex) {
	//	info->description = ZH_WORDS_GETTER("employee.field.sex");
	//}
	// 年龄
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("employee.field.age");
	}
	//编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
	}
	//组织
	DTO_FIELD(String, organize);
	DTO_FIELD_INFO(organize) {
		info->description = ZH_WORDS_GETTER("employee.field.organize");
	}
	//部门
	DTO_FIELD(String, depart);
	DTO_FIELD_INFO(depart) {
		info->description = ZH_WORDS_GETTER("employee.field.depart");
	}
	//职务
	DTO_FIELD(String, job);
	DTO_FIELD_INFO(job) {
		info->description = ZH_WORDS_GETTER("employee.field.job");
	}
	//岗位
	DTO_FIELD(String, post);
	DTO_FIELD_INFO(post) {
		info->description = ZH_WORDS_GETTER("employee.field.post");
	}
	//证件号
	DTO_FIELD(String, idMum);
	DTO_FIELD_INFO(idMum) {
		info->description = ZH_WORDS_GETTER("employee.field.idMum");
	}
	//出生日期
	DTO_FIELD(String, birthday);
	DTO_FIELD_INFO(birthday) {
		info->description = ZH_WORDS_GETTER("employee.field.birthday");
	}
	//手机号码
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("employee.field.phone");
	}
	//员工状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("employee.field.state");
	}
};

/**
 * 示例分页传输对象
 */
class EmployeeInformationPageDTO : public PageDTO<EmployeeInformationDTO::Wrapper>
{
	DTO_INIT(EmployeeInformationPageDTO, PageDTO<EmployeeInformationDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEE_INFOMATION_DTO_