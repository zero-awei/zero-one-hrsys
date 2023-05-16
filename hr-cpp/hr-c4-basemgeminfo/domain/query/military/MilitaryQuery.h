#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/15 20:06:39

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
#ifndef _MILITARYQUERY_H_
#define _MILITARYQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MilitaryDetailQuery : public oatpp::DTO
{
	DTO_INIT(MilitaryDetailQuery, DTO);
	
	// 军转干部主键标识
	DTO_FIELD(String, PIMARMYCADRESID);
	DTO_FIELD_INFO(PIMARMYCADRESID) {
		info->description = ZH_WORDS_GETTER("military.PIMARMYCADRESID");
	}
};

class MilitaryDownloadQuery : public oatpp::DTO
{
	DTO_INIT(MilitaryDownloadQuery, DTO);

	// 军转干部 人员信息标识
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("military.PIMPERSONID");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MILITARYQUERY_H_