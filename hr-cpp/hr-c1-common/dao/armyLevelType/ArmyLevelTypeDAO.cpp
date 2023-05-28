/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/23 23:42:52

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
#include "stdafx.h"
#include "ArmyLevelTypeDAO.h"
#include "ArmyLevelMapper.h"

std::list<ArmyLevelTypeDO> ArmyLevelTypeDAO::selectAll()
{
	/*string str = "SELECT `LEVELTYPE` FROM `t_pimarmycadres` GROUP BY `LEVELTYPE`";
	ArmyLevelMapper mapper;
	return sqlSession->executeQuery<ArmyLevelTypeDO, ArmyLevelMapper>(str, mapper);*/

	list<ArmyLevelTypeDO> res;
	for (auto item : armyLevel)
	{
		ArmyLevelTypeDO tmp(item.first, item.second);
		res.push_back(tmp);
	}
	return res;
}

unordered_map<string, string> ArmyLevelTypeDAO::getMapList()
{
	return armyLevel;
}