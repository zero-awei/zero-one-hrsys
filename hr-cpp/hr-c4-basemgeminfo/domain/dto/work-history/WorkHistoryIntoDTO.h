#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/16 10:12:44

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
#ifndef _WORKHISTORYINTODTO_H_
#define _WORKHISTORYINTODTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class WorkHistorysIntoDTO : public oatpp::DTO
{
	DTO_INIT(WorkHistorysIntoDTO, DTO);


	////任职开始时间
	//DTO_FIELD(String, rzkssj);
	//DTO_FIELD_INFO(rzkssj) {
	//	info->description = ZH_WORDS_GETTER("workhistory.field.rzkssj");
	//}


	////任职结束时间
	//DTO_FIELD(String, rzjssj);
	//DTO_FIELD_INFO(rzjssj) {
	//	info->description = ZH_WORDS_GETTER("workhistory.field.rzjssj");
	//}

	////工作单位
	//DTO_FIELD(String, ormorgname);
	//DTO_FIELD_INFO(ormorgname) {
	//	info->description = ZH_WORDS_GETTER("workhistory.field.ormorgname");
	//}

	////4部门
	//DTO_INIT_(String, ormorgsectorname, "workhistory.field.ormorgsectorname")

	////5职务
	//DTO_INIT_(String, ormdutyname, "workhistory.field.ormdutyname")

	////6岗位
	//DTO_INIT_(String, ormpostname, "workhistory.field.ormpostname")

	////7兼职借调类型
	//DTO_INIT_(String, cfplx, "workhistory.field.cfplx")

	////8是否主要经历
	//DTO_INIT_(UInt64, experience, "workhistory.field.experience")

	////8是否主要经历
	//DTO_INIT_(String, pimworkhistoryid, "workhistory.field.pimworkhistoryid")

	//9人员信息id
	DTO_INIT_(String, pimpersonid, "workhistory.field.pimpersonid")


	//导入文件后缀名
	DTO_INIT_(String, suffix, "workhistory.field.suffix")



	//导出文件主体
	DTO_INIT_(String, body, "workhistory.field.body")

};


/*class WorkHistoryIntoDTO : public oatpp::DTO
{
	DTO_INIT(WorkHistoryIntoDTO, DTO);

	//批量增加list
	DTO_FIELD(List<WorkHistorysDTO>, listworkhistory) = {};
	DTO_FIELD_INFO(listworkhistory) {
		info->description = ZH_WORDS_GETTER("workhistory.field.listworkhistory");
	}

	//8人员信息id
	DTO_INIT_(String, pimpersonid, "workhistory.field.pimpersonid")
	
};*/

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYINTODTO_H_