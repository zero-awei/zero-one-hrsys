#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/17 8:55:44

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
#ifndef _WORKHISTORYEXPORTDTO_H_
#define _WORKHISTORYEXPORTDTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class WorkHistoryExportDTO : public oatpp::DTO
{
public:

	WorkHistoryExportDTO() = default;
	WorkHistoryExportDTO(String rzkssj, String rzjssj, String ormorgname, \
		String ormorgsectorname, String ormdutyname, String ormpostname, String cfplx, \
		UInt64 experience, String pimpersonid, String pimworkhistoryid) : rzkssj(rzkssj), \
		rzjssj(rzjssj), ormorgname(ormorgname), ormorgsectorname(ormorgsectorname),\
		ormdutyname(ormdutyname), ormpostname(ormpostname), cfplx(cfplx), experience(experience),\
		pimpersonid(pimpersonid) , pimworkhistoryid(pimworkhistoryid){}
private:


	DTO_INIT(WorkHistoryExportDTO, DTO);
	
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

	//9工作履历信息id
	DTO_FIELD(String, pimworkhistoryid);
	DTO_FIELD_INFO(pimworkhistoryid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimworkhistoryid");
	}

	//10人员信息id
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimpersionid");
	}
};

class WorkHistoryExportPageDTO : public PageDTO<WorkHistoryExportDTO::Wrapper>
{
	DTO_INIT(WorkHistoryExportPageDTO, PageDTO<WorkHistoryExportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYEXPORTDTO_H_