#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/26 16:25:50

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
#ifndef _WORKHISTORYMQDTO_H_
#define _WORKHISTORYMQDTO_H_

#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class WorkHistoryMqDTO : public oatpp::DTO
{
	DTO_INIT(WorkHistoryMqDTO, DTO);
	
	//10人员信息id
	DTO_FIELD(String, pimpersonid);
	DTO_FIELD_INFO(pimpersonid) {
		info->description = ZH_WORDS_GETTER("workhistory.field.pimpersionid");
	}

	DTO_INIT_(String, body, "workhistory.field");

	DTO_INIT_(String, creatName, "workhistory.field");
	//DTO_INIT_(String)
	//DTO_INIT_(String, suffix, "workhistory.field.pimpersionid");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKHISTORYMQDTO_H_