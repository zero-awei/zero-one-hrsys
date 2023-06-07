#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: guyier
 @Date: 2023/05/17 14:17:22

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
#ifndef _Employee_Languare_Query
#define _Employee_Languare_Query

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 查询指定员工语言能力
 */
class EmployeeLanguareQuery : public oatpp::DTO
{
	DTO_INIT(EmployeeLanguareQuery, DTO);

	//语言能力
	//语种
	DTO_FIELD(String, Language);
	DTO_FIELD_INFO(Language) {
		info->description = ZH_WORDS_GETTER("employee.language.summary");
	}
	//外语等级
	DTO_FIELD(String, foreignLanguageLevel);
	DTO_FIELD_INFO(foreignLanguageLevel) {
		info->description = ZH_WORDS_GETTER("employee.language.foreignLanguageLevel");
	}
	//外语等级获取时间
	DTO_FIELD(String,time);
	DTO_FIELD_INFO(time) {
		info->description = ZH_WORDS_GETTER("employee.language.time");
	}
	//附件
	DTO_FIELD(String,peoject);
	DTO_FIELD_INFO(peoject) {
		info->description = ZH_WORDS_GETTER("employee.language.peoject");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
