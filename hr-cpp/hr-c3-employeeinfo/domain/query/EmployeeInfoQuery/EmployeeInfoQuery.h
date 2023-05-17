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
#ifndef _EMPLOYEEINFOQUERY_H_
#define _EMPLOYEEINFOQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EmployeeInfoQuery : public PageQuery
{
	DTO_INIT(EmployeeInfoQuery, PageQuery);
	//员工编号
	DTO_FIELD(UInt64, empid);
	DTO_FIELD_INFO(empid) {
		info->description = ZH_WORDS_GETTER("employee.field.id");
	}
	//员工姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("employee.field.name");
	}
	//证件类型
	DTO_FIELD(String, idtype);
	DTO_FIELD_INFO(idtype) {
		info->description = ZH_WORDS_GETTER("employee.field.idtype");
	}
	//证件号码
	DTO_FIELD(Int32, idnum);
	DTO_FIELD_INFO(idnum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
	}
	//出生日期
	DTO_FIELD(Int32, idnum);
	DTO_FIELD_INFO(idnum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
	}
	// 年龄
	DTO_FIELD(Int32, idnum);
	DTO_FIELD_INFO(idnum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
	}
	// 性别
	DTO_FIELD(Int32, idnum);
	DTO_FIELD_INFO(idnum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
	}
	// 民族
	DTO_FIELD(Int32, idnum);
	DTO_FIELD_INFO(idnum) {
		info->description = ZH_WORDS_GETTER("employee.field.idnum");
	}
	// 籍贯
	// 婚姻状况
	// 政治面貌
	// 职级
	// 参加工作时间
	// 到本单位时间
	// 电子邮箱
	// 技术职称
	// 最高学历
	// 第一学历
	// 执业证书
	// 照片路径
	//手机号码
	DTO_FIELD(Int32, phonenum);
	DTO_FIELD_INFO(phonenum) {
		info->description = ZH_WORDS_GETTER("employee.field.phone");
	}
	//员工状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("employee.field.state");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EMPLOYEEINFOQUERY_H_