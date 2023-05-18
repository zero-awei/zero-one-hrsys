#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/17 20:01:54

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
#ifndef _EMPLOYEEINFODTO_H_
#define _EMPLOYEEINFODTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//修改具体员工信息
class EmployeeInfoDTO : public oatpp::DTO
{
	DTO_INIT(EmployeeInfoDTO, DTO);
	//员工编号
	DTO_FIELD(UInt64, empid);
	DTO_FIELD_INFO(empid) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
		info->required = true;
	}
	//员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("employee.field.name");
		info->required = true;
	}
	//证件类型
	DTO_FIELD(String, idtype);
	DTO_FIELD_INFO(idtype) {
		info->description = ZH_WORDS_GETTER("employee.field.idtype");
		info->required = true;
	}
	//证件号码
	DTO_FIELD(Int32, idnum);
	DTO_FIELD_INFO(idnum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
		info->required = true;
	}
	//出生日期
	DTO_FIELD(String, bthdate);
	DTO_FIELD_INFO(bthdate) {
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
	//血型
	API_DTO_FIELD_DEFAULT(String, blood, ZH_WORDS_GETTER("employee.field.blood"));
	// 民族
	DTO_FIELD(String, nation);
	DTO_FIELD_INFO(nation) {
		info->description = ZH_WORDS_GETTER("employee.field.nation");
	}
	//户口类型
	API_DTO_FIELD_DEFAULT(String, residentType, ZH_WORDS_GETTER("employee.field.residentType"));
	// 籍贯
	DTO_FIELD(String, native);
	DTO_FIELD_INFO(native) {
		info->description = ZH_WORDS_GETTER("employee.field.native");
	}
	//户籍所在地
	API_DTO_FIELD_DEFAULT(String, residentPlace, ZH_WORDS_GETTER("employee.field.residentPlace"));
	// 户籍地址
	API_DTO_FIELD_DEFAULT(String, residentLocate, ZH_WORDS_GETTER("employee.field.residentLocate"));
	// 出生地址
	API_DTO_FIELD_DEFAULT(String, birthPlace, ZH_WORDS_GETTER("employee.field.birthPlace"));
	// 通讯地址
	API_DTO_FIELD_DEFAULT(String, comPlace, ZH_WORDS_GETTER("employee.field.comPlace"));
	// 有独生子女证
	API_DTO_FIELD_DEFAULT(Boolean, onlyCredit, ZH_WORDS_GETTER("employee.field.onlyCredit"));
	// 爱好特长
	API_DTO_FIELD_DEFAULT(String, hobby, ZH_WORDS_GETTER("employee.field.hobby"));
	// 健康状况
	API_DTO_FIELD_DEFAULT(String, health, ZH_WORDS_GETTER("employee.field.health"));
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
		info->required = true;
	}
	//员工状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("employee.field.state");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEEINFODTO_H_