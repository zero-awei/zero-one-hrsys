#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/14 21:08:39

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
#ifndef _WORKHISTORYFINDDTO_H_
#define _WORKHISTORYFINDDTO_H_

#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class WorkHistoryFindDTO : public oatpp::DTO
{
public:
	WorkHistoryFindDTO() = default;
	WorkHistoryFindDTO(String rzkssj, String rzjssj, String ormorgname, \
		String ormorgsectorname, String ormdutyname, String ormpostname, String cfplx, \
		UInt64 experience, String pimpersonid, String pimworkhistoryid) : rzkssj(rzkssj), \
		rzjssj(rzjssj), ormorgname(ormorgname), ormorgsectorname(ormorgsectorname), \
		ormdutyname(ormdutyname), ormpostname(ormpostname), cfplx(cfplx), experience(experience), \
		pimpersonid(pimpersonid), pimworkhistoryid(pimworkhistoryid) {}

	DTO_INIT(WorkHistoryFindDTO, DTO);
	
	//任职开始时间
	DTO_FIELD(String, rzkssj);
	DTO_FIELD_INFO(rzkssj) {
		info->description = ZH_WORDS_GETTER("workhistory.field.rzkssj");
	}


	//任职结束时间
	DTO_FIELD(String, rzjssj);
	DTO_FIELD_INFO(rzjssj) {
		info->description = ZH_WORDS_GETTER("workhistory.field.rzjssj");
	}

	//工作单位
	DTO_FIELD(String, ormorgname);
	DTO_FIELD_INFO(ormorgname) {
		info->description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
	}

	//4部门
	DTO_INIT_(String, ormorgsectorname, "workhistory.field.ormorgsectorname")

		//5职务
	DTO_INIT_(String, ormdutyname, "workhistory.field.ormdutyname")

		//6岗位
	DTO_INIT_(String, ormpostname, "workhistory.field.ormpostname")

	//7兼职借调类型
	DTO_FIELD(String, cfplx);
	DTO_FIELD_INFO(cfplx) {
		info->description = ZH_WORDS_GETTER("workhistory.field.cfplx");
	}

	//8是否主要经历
	DTO_FIELD(UInt64, experience);
	DTO_FIELD_INFO(experience) {
		info->description = ZH_WORDS_GETTER("workhistory.field.experience");
	}

	//9人员信息id
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimpersionid");
	}

	//10工作履历id
	//工作履历id
	DTO_INIT_(String, pimworkhistoryid, "workhistory.field.pimworkhistoryid")
};

class WorkHistoryFindPageDTO : public PageDTO<WorkHistoryFindDTO::Wrapper>
{
	DTO_INIT(WorkHistoryFindPageDTO, PageDTO<WorkHistoryFindDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYFINDDTO_H_