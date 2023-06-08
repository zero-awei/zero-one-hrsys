/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/24 19:57:18

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONVO_H_
#define _REWARDANDPUNISHMENTINFORMATIONVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/rewardandpunishmentinformation/RewardAndPunishmentInformationDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class RewardAndPunishmentInformationJsonVO : public JsonVO<RewardAndPunishmentInformationDTO::Wrapper>
{
	DTO_INIT(RewardAndPunishmentInformationJsonVO, JsonVO < RewardAndPunishmentInformationDTO::Wrapper>);
};

class RewardAndPunishmentInformationPageJsonVO : public  JsonVO<RewardAndPunishmentInformationPageDTO::Wrapper>
{
	DTO_INIT(RewardAndPunishmentInformationPageJsonVO, JsonVO < RewardAndPunishmentInformationPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REWARDANDPUNISHMENTINFORMATIONVO_H_