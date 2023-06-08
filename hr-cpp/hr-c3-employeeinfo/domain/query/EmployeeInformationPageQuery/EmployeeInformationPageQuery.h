#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2022/10/25 11:36:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _EMPLOYEE_INFORMATION_PAGE_QUERY
#define _EMPLOYEE_INFORMATION_PAGE_QUERY

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class EmployeeInformationPageQuery : public PageQuery
{
	DTO_INIT(EmployeeInformationPageQuery, PageQuery);
	//人员信息标识
	DTO_FIELD(String, personId);
	DTO_FIELD_INFO(personId) {
		info->description = ZH_WORDS_GETTER("employee.field.personId");
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

#include OATPP_CODEGEN_END(DTO)
#endif // !_EMPLOYEE_INFORMATION_PAGE_QUERY