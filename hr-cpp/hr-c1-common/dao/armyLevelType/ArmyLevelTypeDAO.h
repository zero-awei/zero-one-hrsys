#pragma once
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
#ifndef _ARMYLEVELTYPEDAO_H_
#define _ARMYLEVELTYPEDAO_H_

#include "BaseDAO.h"
#include "domain/do/armyLevelType/ArmyLevelTypeDO.h"

class ArmyLevelTypeDAO : public BaseDAO
{
private:
	// 军转级别对应哈希表
	unordered_map<string, string> armyLevel = {
		{"6171", u8"正营职"},
		{"6191", u8"正排职"},
		{"6163", u8"副团职"},
		{"6183", u8"副连职"},
		{"6153", u8"副师职（正旅职）"},
		{"6173", u8"副营职"},
		{"6151", u8"正师职"},
		{"6161", u8"正团职（副旅职）"},
		{"6181", u8"正连职"}
	};
public:
	// 查询数据
	list<ArmyLevelTypeDO> selectAll();
	// 返回下拉列表
	unordered_map<string, string> getMapList();
};

#endif // !_ARMYLEVELTYPEDAO_H_