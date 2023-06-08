#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/29 20:47:57

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
#ifndef _TYPECONTRACTDAO_H_
#define _TYPECONTRACTDAO_H_

#include "BaseDAO.h"
#include "domain/do/awardLevels/ArchivesLevelsDO.h"

/**
 * 合同类型下拉列表DAO实现
 * 负责人：Andrew
 */
class AwardLevelDAO : public BaseDAO
{
private:
	// 获奖等级映射表
	std::unordered_map<string, string> awardLevel = {
		{"10", u8"国家级"},
		{"20", u8"省（自治区、直辖市）级"},
		{"30", u8"部委级"},
		{"40", u8"地（市、厅）级"},
		{"50", u8"区（县）级"},
		{"60", u8"基层单位"},
		{"70", u8"国际国外"},
		{"80", u8"学校校级"},
		{"90", u8"学校院级"}
	};
public:
	std::list<ArchivesLevelsDO> selectAll();
	std::unordered_map<string, string> getAwardLevel();
};

#endif // !_TYPECONTRACTDAO_H_