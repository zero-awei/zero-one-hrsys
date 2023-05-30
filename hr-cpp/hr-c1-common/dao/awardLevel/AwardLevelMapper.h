#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/26 22:54:52

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
#ifndef _TYPECONTRACTMAPPER_H_
#define _TYPECONTRACTMAPPER_H_

#include "Mapper.h"
#include "domain/do/awardLevels/ArchivesLevelsDO.h"

/**
 * 获奖等级字段映射
 * 负责人：yuanchen
 */
class AwardLevelMapper : public Mapper<ArchivesLevelsDO>
{
public:
	ArchivesLevelsDO mapper(ResultSet* resultSet) const override
	{
		ArchivesLevelsDO data;

		data.setPcmawardswonsid(resultSet->getString(1));
		data.setAwardlevel(resultSet->getString(2));
		return data;
	}
};

#endif // !_TYPECONTRACTMAPPER_H_#pragma once
