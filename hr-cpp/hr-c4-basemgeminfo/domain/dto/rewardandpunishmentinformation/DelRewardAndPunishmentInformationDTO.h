#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/24 17:21:23

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
#ifndef _DELREWARDANDPUNISHMENTINFORMATIONDTO_H_
#define _DELREWARDANDPUNISHMENTINFORMATIONDTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DelRewardAndPunishmentInformationDTO : public oatpp::DTO
{
	DTO_INIT(DelRewardAndPunishmentInformationDTO, DTO);
	DTO_FIELD(List<String>, deleteById) = {};
	DTO_FIELD_INFO(deleteById)
	{
		info->description = ZH_WORDS_GETTER("rewardandpunishmentinformation.field.list<pimrewardpunishmentid>");
	}

	DTO_INIT_(String, pimpersonid, "rewardandpunishmentinformation.field.pimpersonid")
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELREWARDANDPUNISHMENTINFORMATIONDTO_H_