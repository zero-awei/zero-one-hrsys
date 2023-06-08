#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/17 19:18:52

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
#ifndef _FAMILYSITUATIONQUERY_H_
#define _FAMILYSITUATIONQUERY_H_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 员工家庭情况查询对象
 */
class FamilysituationQuery : public PageQuery
{
	DTO_INIT(FamilysituationQuery, PageQuery);
	// 员工编号
	API_DTO_FIELD_DEFAULT(String, personid, ZH_WORDS_GETTER("familysituation.field.personid"));
	//家庭情况编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("familysituation.field.id"));
	//关系
	API_DTO_FIELD_DEFAULT(String, frelationship, ZH_WORDS_GETTER("familysituation.field.relationship"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("familysituation.field.name"));
	// 性别
	API_DTO_FIELD_DEFAULT(String, gender, ZH_WORDS_GETTER("familysituation.field.gender"));
	// 年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("familysituation.field.age"));
	// 工作单位
	API_DTO_FIELD_DEFAULT(String, workplace, ZH_WORDS_GETTER("familysituation.field.workplace"));

	// 职务
	DTO_FIELD(String, job);
	DTO_FIELD_INFO(job) {
		info->description = ZH_WORDS_GETTER("familysituation.field.job");
	}

	// 政治面貌
	DTO_FIELD(String, politicalstatus);
	DTO_FIELD_INFO(politicalstatus) {
		info->description = ZH_WORDS_GETTER("familysituation.field.politicalstatus");
	}

	// 证件类型
	DTO_FIELD(String, doctype);
	DTO_FIELD_INFO(doctype) {
		info->description = ZH_WORDS_GETTER("familysituation.field.identification");
	}

	// 证件号
	DTO_FIELD(String, identification);
	DTO_FIELD_INFO(identification) {
		info->description = ZH_WORDS_GETTER("familysituation.field.identification");
	}

	// 出生日期
	DTO_FIELD(String, dob);
	DTO_FIELD_INFO(dob) {
		info->description = ZH_WORDS_GETTER("familysituation.field.dob");
	}

	// 是否遗嘱
	DTO_FIELD(Int8, testament);
	DTO_FIELD_INFO(testament) {
		info->description = ZH_WORDS_GETTER("familysituation.field.testament");
	}

	// 是否紧急联系人
	DTO_FIELD(String, ice);
	DTO_FIELD_INFO(ice) {
		info->description = ZH_WORDS_GETTER("familysituation.field.ice");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_FAMILYSITUATIONQUERY_H_