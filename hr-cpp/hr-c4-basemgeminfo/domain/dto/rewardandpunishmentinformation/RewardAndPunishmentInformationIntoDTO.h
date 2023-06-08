#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/24 19:16:46

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONINTODTO_H_
#define _REWARDANDPUNISHMENTINFORMATIONINTODTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"
#include "AddRewardAndPunishmentInformationDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class RewardAndPunishmentInformationIntoDTO : public oatpp::DTO
{
	DTO_INIT(RewardAndPunishmentInformationIntoDTO, DTO);
	
	//人员信息id
	DTO_INIT_(String, pimpersonid, "rewardandpunishmentinformation.field.pimpersonid")

	//导入文件后缀名
	DTO_INIT_(String, suffix, "rewardandpunishmentinformation.field.suffix")

	//导出文件主体
	DTO_INIT_(String, body, "rewardandpunishmentinformation.field.body")


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REWARDANDPUNISHMENTINFORMATIONINTODTO_H_