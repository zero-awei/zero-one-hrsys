#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/15 15:20:19

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
#ifndef _ADDWORKHISTORYDTO_H_
#define _ADDWORKHISTORYDTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddWorkHistoryDTO : public oatpp::DTO
{
	DTO_INIT(AddWorkHistoryDTO, DTO);
	
	//8人员信息id
	DTO_INIT_(String, pimpersonid, "workhistory.field.pimpersonid")

	////1任职开始时间
	DTO_INIT_(String, servebegintime, "workhistory.field.servebegintime")


	//2任职结束时间
	DTO_INIT_(String, serveendtime, "workhistory.field.serveendtime")

	//3工作单位
	DTO_INIT_(String, workunit, "workhistory.field.workunit")

	//4部门
	DTO_INIT_(String, bm, "workhistory.field.bm")

	//5职务
	DTO_INIT_(String, zw, "workhistory.field.zw")

	//6岗位
	DTO_INIT_(String, gw, "workhistory.field.gw")

	//7职级
	DTO_INIT_(String, ormrankid, "workhistory.field.ormrankid")

	
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDWORKHISTORYDTO_H_