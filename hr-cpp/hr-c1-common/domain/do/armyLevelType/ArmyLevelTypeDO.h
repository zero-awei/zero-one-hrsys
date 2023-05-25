#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/23 21:36:57

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
#ifndef _ARMYLEVELTYPEDO_H_
#define _ARMYLEVELTYPEDO_H_

#include "../DoInclude.h"
/**
 * 军转级别下拉列表
 * 负责人：yuanchen
 */
class ArmyLevelTypeDO
{
	// 军转级别下拉列表--军转级别
	CC_SYNTHESIZE(string, armyLevelType, ArmyLevelType);
	// 军转级别代码
	CC_SYNTHESIZE(string, code, Code);
public:
	ArmyLevelTypeDO()
	{
		code = "";
		armyLevelType = "";
	}

	ArmyLevelTypeDO(string code_, string level_)
	{
		code = code_;
		armyLevelType = level_;
	}
};

#endif // !_DISMISSREASONDO_H_