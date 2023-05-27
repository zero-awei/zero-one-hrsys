#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ahao
 @Date: 2022/5/26 14:21:55

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
#ifndef _ASSIGN_INFO_MAPPER_
#define _ASSIGN_INFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/assignInfoDO/AssignInfoDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class AssignInfoMapper : public Mapper<AssignInfoDO>
{
public:
	AssignInfoDO mapper(ResultSet* resultSet) const override
	{
		AssignInfoDO data;
		data.setId(resultSet->getString(1));
		data.setAssign(resultSet->getString(2));
		data.setEtype(resultSet->getString(3));
		data.setOrganize(resultSet->getString(4));
		data.setDepart(resultSet->getString(5));
		data.setJob(resultSet->getString(6));
		data.setPost(resultSet->getString(7));
		data.setStartTime(resultSet->getString(8));
		data.setEndTime(resultSet->getString(9));
		return data;
	}
};

#endif // !_ASSIGN_INFO_MAPPER_