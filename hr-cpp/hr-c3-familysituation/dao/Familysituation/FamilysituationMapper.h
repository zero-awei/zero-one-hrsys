#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Marvin
 @Date: 2023/05/30 11:48:19

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
#ifndef _FAMILYSITUATIONMAPPER_H_
#define _FAMILYSITUATIONMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/Familysituation/FamilysituationDO.h"

class FamilysituationMapper : public Mapper<FamilysituationDO>
{
public:
	FamilysituationDO mapper(ResultSet* resultSet) const override
	{
		FamilysituationDO data;
		data.setId(resultSet->getString(1));
		data.setPersonId(resultSet->getString(15));
		data.setName(resultSet->getString(2));
		data.setRelationship(resultSet->getString(7));
		data.setDoctype(resultSet->getString(21));
		data.setIdentification(resultSet->getString(16));
		data.setGender(resultSet->getString(8));
		data.setDob(resultSet->getString(9));
		data.setAge(resultSet->getInt(10));
		data.setWorkplace(resultSet->getString(12));
		data.setJob(resultSet->getString(13));
		data.setPoliticalstatus(resultSet->getString(11));
		data.setTestament(resultSet->getInt(24));
		data.setIce(resultSet->getString(14));

		return data;
	}
};

#endif // !_FAMILYSITUATIONMAPPER_H_