#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/24 13:28:40

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
#ifndef _EMPLOYEE_INfORMATION_PAGE_DO_
#define _EMPLOYEE_INfORMATION_PAGE_DO_
#include "../DoInclude.h"

/*
分页查询实体类
*/
class EmployeeInformationPageDO
{
	//人员信息标识
	CC_SYNTHESIZE(string, personId, PersonId);
	//建立人
	CC_SYNTHESIZE(string, createMan, CreateMan);
	//建立时间
	CC_SYNTHESIZE(string, createDate, CreateDate);

	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 年龄
	CC_SYNTHESIZE(int32_t, age, Age);
	//编号
	CC_SYNTHESIZE(string, id, Id);
	//组织
	CC_SYNTHESIZE(string, organize, Organize);
	//部门
	CC_SYNTHESIZE(string, depart, Depart);
	//职务
	CC_SYNTHESIZE(string, job, Job);
	//岗位
	CC_SYNTHESIZE(string, post, Post);
	//证件号
	CC_SYNTHESIZE(string, idMum, IdMum);
	//出生日期
	CC_SYNTHESIZE(string, birthday, Birthday);
	//手机号码
	CC_SYNTHESIZE(string, phone, Phone);
	//员工状态
	CC_SYNTHESIZE(string, state, State);
public:
	EmployeeInformationPageDO() {
		personId = "";
		name = "";
		age = 0;
		id = "";
		organize = "";
		depart = "";
		job = "";
		post = "";
		idMum = "";
		birthday = "";
		phone = "";
		state = "";
	}
};

#endif // !_EMPLOYEE_INfORMATION_PAGE_DO_
