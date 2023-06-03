#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/24 16:17:01

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
#ifndef _FAMILYSITUATIONDO_H_
#define _FAMILYSITUATIONDO_H_
#include "../DoInclude.h"

/**
 * 家庭情况数据库实体类
 */
class FamilysituationDO
{
	// 家庭情况编号
	CC_SYNTHESIZE(string, id, Id);
	// 员工编号
	CC_SYNTHESIZE(string, personid, PersonId);
	// 关系
	CC_SYNTHESIZE(string, frelationship, Relationship);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, gender, Gender);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 工作单位
	CC_SYNTHESIZE(string, workplace, Workplace);
	// 职务
	CC_SYNTHESIZE(string, job, Job);
	// 政治面貌
	CC_SYNTHESIZE(string, politicalstatus, Politicalstatus);
	// 证件类型
	CC_SYNTHESIZE(string, doctype, Doctype);
	// 证件号
	CC_SYNTHESIZE(string, identification, Identification);
	// 出生日期
	CC_SYNTHESIZE(string, dob, Dob);
	// 是否遗嘱
	CC_SYNTHESIZE(int, testament, Testament);
	// 是否紧急联系人
	CC_SYNTHESIZE(string, ice, Ice);
	// 权限验证人员ID
	CC_SYNTHESIZE(string, authid, AuthId);
	// 操作时间
	CC_SYNTHESIZE(string, opertime, Opertime);
public:
	FamilysituationDO() {
		id = "";
		personid = "";
		frelationship = "";
		name = "";
		gender = "";
		age = -1;
		workplace = "";
		job = "";
		politicalstatus = "";
		doctype = "";
		identification = "";
		dob = "";
		testament = -1;
		ice = "";
		authid = "";
		opertime = "";
	}
};

#endif // !_FAMILYSITUATIONDO_H_