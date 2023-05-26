#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/25 19:24:18

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
#ifndef _ARMYLEVELMAPPER_H_
#define _ARMYLEVELMAPPER_H_

#include "Mapper.h"
#include "domain/do/armyLevelType/ArmyLevelTypeDO.h"

/**
 * 军转级别下拉列表数据库字段匹配映射
 * 负责人：Andrew
 */
class ArmyLevelMapper : public Mapper<ArmyLevelTypeDO>
{
public:
	ArmyLevelTypeDO mapper(ResultSet *result) const override
	{
		ArmyLevelTypeDO data;
		data.setArmyLevelType(result->getString(1));
		return data;
	}
};

#endif // !_ARMYLEVELMAPPER_H_