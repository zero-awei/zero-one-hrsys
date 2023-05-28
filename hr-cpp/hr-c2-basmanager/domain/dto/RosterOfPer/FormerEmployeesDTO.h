
/**
 * 人员花名册 - 离职人员DTO实现 - 楚孟献
 */
/*
 Copyright Zero One Star. All rights reserved.
 @Author: awei
 @Date: $DATE$ $HOUR$:$MINUTE$:$SECOND$
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
#ifndef _FORMER_EMPLOYEES_DTO_
#define _FORMER_EMPLOYEES_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class FormerEmployeesDTO : public oatpp::DTO
{

    DTO_INIT(FormerEmployeesDTO, DTO);
    
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.name");
	}
	// 手机号码
	DTO_FIELD(String, phoneNumber);
	DTO_FIELD_INFO(phoneNumber) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.phonenumber");
	}
	// 年龄
	DTO_FIELD(Int32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.age");
	}
	// 出生日期
	DTO_FIELD(String, chushengriqi);
	DTO_FIELD_INFO(chushengriqi) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.dateofbirth");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.sex");
	}
	// 组织
	DTO_FIELD(String, organization);
	DTO_FIELD_INFO(organization) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.organization");
	}
	// 部门
	DTO_FIELD(String, department);
	DTO_FIELD_INFO(department) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.department");
	}
	// 职级
	DTO_FIELD(String, rank);
	DTO_FIELD_INFO(rank) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.rank");
	}
	// 通讯地址
	DTO_FIELD(String, mail_address);
	DTO_FIELD_INFO(mail_address) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.mail_address");
	}
	// 家庭联系人
	DTO_FIELD(String, family_contact);
	DTO_FIELD_INFO(family_contact) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.family_contact");
	}
	// 家庭联系人电话
	DTO_FIELD(String, family_contact_number);
	DTO_FIELD_INFO(family_contact_number) {
		info->description = ZH_WORDS_GETTER("formeremployees.field.family_contact_number");
	}
};

/**
 * 离职员工分页传输对象
 */
class FormerEmployeesPageDTO : public PageDTO<FormerEmployeesDTO::Wrapper>
{
	DTO_INIT(FormerEmployeesPageDTO, PageDTO<FormerEmployeesDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_$FILE_BASE_UPPER$_H
