#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: arui
 @Date: 2023/05/25 1:20:13

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
#ifndef _REWARDANDPUNISHMENTINFORMATIONMAPPER_H_
#define _REWARDANDPUNISHMENTINFORMATIONMAPPER_H_
#include "Mapper.h"
#include "domain/do/rewardandpunishmentinformation/RewardAndPunishmentInformationDO.h"
class RewardAndPunishmentInformationMapper : public Mapper<RewardAndPunishmentInformationDO>
{
public:
	RewardAndPunishmentInformationDO mapper(ResultSet* resultSet) const override
	{
		RewardAndPunishmentInformationDO data;
		data.setLx(resultSet->getString(1));
		data.setPimrewardpunishmentname(resultSet->getString(2));
		data.setJcjb(resultSet->getString(3));
		data.setJcje(resultSet->getDouble(4));
		data.setJlsj(resultSet->getString(5));
		data.setJcsj(resultSet->getString(6));
		data.setBz(resultSet->getString(7));
		data.setFj(resultSet->getString(8));
		
		return data;
	}
};

#endif // !_REWARDANDPUNISHMENTINFORMATIONMAPPER_H_