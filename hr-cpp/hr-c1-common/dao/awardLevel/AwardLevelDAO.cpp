/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanchen
 @Date: 2023/05/29 20:52:33

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
#include "AwardLevelDAO.h"
#include "domain/do/awardLevels/ArchivesLevelsDO.h"
#include "AwardLevelMapper.h"
std::list<ArchivesLevelsDO> AwardLevelDAO::selectAll()
{
	// ¹¹½¨SQL²éÑ¯Óï¾ä
	/*string str = "SELECT `PCMAWARDSWONSID`, `AWARDLEVEL` FROM `t_pcmawardswons`";
	AwardLevelMapper mapper;
	return sqlSession->executeQuery<ArchivesLevelsDO, AwardLevelMapper>(str, mapper);*/

	std::list<ArchivesLevelsDO> res;
	for (auto level : awardLevel)
	{
		ArchivesLevelsDO tmp(level.first, level.second);
		res.push_back(tmp);
	}
	return res;
}

std::unordered_map<std::string, std::string> AwardLevelDAO::getAwardLevel()
{
	return awardLevel;
}
