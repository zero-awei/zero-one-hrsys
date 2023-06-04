#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/24 22:43:10

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONSERVICE_H_
#define _REWARDANDPUNISHMENTINFORMATIONSERVICE_H_
#include <list>
#include "domain/vo/rewardandpunishmentinformation/RewardAndPunishmentInformationVO.h"
#include "domain/query/rewardandpunishmentinformation/RewardAndPunishmentInformationPageQuery.h"
#include "domain/dto/rewardandpunishmentinformation/AddRewardAndPunishmentInformationDTO.h"
#include "domain/dto/rewardandpunishmentinformation/DelRewardAndPunishmentInformationDTO.h"
#include "domain/dto/rewardandpunishmentinformation/RewardAndPunishmentInformationDTO.h"
using namespace oatpp;
class RewardAndPunishmentInformationService
{
public:
	RewardAndPunishmentInformationPageDTO::Wrapper listAll(const RewardAndPunishmentInformationPageQuery::Wrapper& query);
	uint64_t saveData(const AddRewardAndPunishmentInformationDTO::Wrapper& dto, const PayloadDTO& payload);
	bool removeData(const DelRewardAndPunishmentInformationDTO::Wrapper& dto);
	uint64_t saveManyData(const String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid, const PayloadDTO& payload);
};

#endif // !_REWARDANDPUNISHMENTINFORMATIONSERVICE_H_