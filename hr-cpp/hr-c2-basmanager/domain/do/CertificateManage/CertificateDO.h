#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _CERTIFICATE_DO_
#define _CERTIFICATE_DO_
#include "../DoInclude.h"

/**
 * 离职员工数据库实体类
 */
class CertificateDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(string, age, Age);
	// 组织
	CC_SYNTHESIZE(string, organization, Organization);
	// 部门
	CC_SYNTHESIZE(string, department, Department);
	// 职级
	CC_SYNTHESIZE(string, rank, Rank);
	// 通讯地址
	CC_SYNTHESIZE(string, mail_address, Mail_address);
	// 家庭联系人
	CC_SYNTHESIZE(string, family_contact, Family_contact);
	// 家庭联系人电话
	CC_SYNTHESIZE(string, family_contact_number, Family_contact_nuimber);

public:
	CertificateDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		organization = "";
		department = "";
		rank = "";
		mail_address = "";
		family_contact = "";
		family_contact_number = "";
	}
};

#endif // !_FPRMERRMPLOYEES_DO_