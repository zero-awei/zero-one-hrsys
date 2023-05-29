#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/17 14:29:04

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
#ifndef _EMPLOYEE_INFO_QUERY_
#define _EMPLOYEE_INFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//查询具体员工信息
class EmployeeInfoQuery : public PageQuery
{
	DTO_INIT(EmployeeInfoQuery, PageQuery);
	//人员信息标识
	API_DTO_FIELD_DEFAULT(String, pimpersonid, ZH_WORDS_GETTER("employee.field.pimpersonid"));
	//员工编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
	}
	//员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("employee.field.name");
	}
	//证件类型
	DTO_FIELD(String, idType);
	DTO_FIELD_INFO(idType) {
		info->description = ZH_WORDS_GETTER("employee.field.idtype");
	}
	//证件号码
	DTO_FIELD(String, idNum);
	DTO_FIELD_INFO(idNum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
	}
	//出生日期
	DTO_FIELD(String, birthday);
	DTO_FIELD_INFO(birthday) {
		info->description = ZH_WORDS_GETTER("employee.field.birthday");
	}
	// 年龄
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("employee.field.age");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("employee.field.sex");
	}
	// 民族
	DTO_FIELD(String, nation);
	DTO_FIELD_INFO(nation) {
		info->description = ZH_WORDS_GETTER("employee.field.nation");
	}
	// 籍贯
	DTO_FIELD(String, native);
	DTO_FIELD_INFO(native) {
		info->description = ZH_WORDS_GETTER("employee.field.native");
	}
	// 婚姻状况
	DTO_FIELD(String, marriage);
	DTO_FIELD_INFO(marriage) {
		info->description = ZH_WORDS_GETTER("employee.field.marriage");
	}
	// 政治面貌
	DTO_FIELD(String, politic);
	DTO_FIELD_INFO(politic) {
		info->description = ZH_WORDS_GETTER("employee.field.politic");
	}
	// 职级
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("employee.field.rank");
	}
	// 参加工作时间
	DTO_FIELD(String, workTime);
	DTO_FIELD_INFO(workTime) {
		info->description = ZH_WORDS_GETTER("employee.field.workTime");
	}
	// 到本单位时间
	DTO_FIELD(String, inTime);
	DTO_FIELD_INFO(inTime) {
		info->description = ZH_WORDS_GETTER("employee.field.inTime");
	}
	// 电子邮箱
	DTO_FIELD(String, email);
	DTO_FIELD_INFO(email) {
		info->description = ZH_WORDS_GETTER("employee.field.email");
	}
	// 技术职称
	DTO_FIELD(String, techTitle);
	DTO_FIELD_INFO(techTitle) {
		info->description = ZH_WORDS_GETTER("employee.field.techTitle");
	}
	// 最高学历
	DTO_FIELD(String, acaCredit);
	DTO_FIELD_INFO(acaCredit) {
		info->description = ZH_WORDS_GETTER("employee.field.acaCredit");
	}
	// 第一学历
	DTO_FIELD(String, firAcaCredit);
	DTO_FIELD_INFO(firAcaCredit) {
		info->description = ZH_WORDS_GETTER("employee.field.firAcaCredit");
	}
	// 执业证书
	DTO_FIELD(String, pracCertificate);
	DTO_FIELD_INFO(pracCertificate) {
		info->description = ZH_WORDS_GETTER("employee.field.pracCertificate");
	}
	// 照片路径
	DTO_FIELD(String, photo);
	DTO_FIELD_INFO(photo) {
		info->description = ZH_WORDS_GETTER("employee.field.photo");
	}
	//手机号码
	DTO_FIELD(String, phone);
	DTO_FIELD_INFO(phone) {
		info->description = ZH_WORDS_GETTER("employee.field.phone");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEE_INFO_QUERY_