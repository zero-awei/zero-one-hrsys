#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 20:03:11

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
#ifndef _MILITARYMAPPER_H_
#define _MILITARYMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/military/MilitaryDO.h"

class MilitaryMapper : public Mapper<MilitaryDO>
{
public:
	MilitaryDO mapper(ResultSet* resultSet) const override
	{
		MilitaryDO data;
		data.set_UPDATEDATE(resultSet->getString(1));
		data.set_PIMARMYCADRESNAME(resultSet->getString(2));
		data.set_FJ(resultSet->getString(3));
		data.set_CREATEDATE(resultSet->getString(4));
		data.set_UPDATEMAN(resultSet->getString(5));
		data.set_ENABLE(resultSet->getString(6));
		data.set_PIMARMYCADRESID(resultSet->getString(7));
		data.set_CREATEMAN(resultSet->getString(8));
		data.set_PIMPERSONID(resultSet->getString(9));
		data.set_FSSJ(resultSet->getString(10));
		data.set_JLSS(resultSet->getString(11));
		data.set_JLSPZT(resultSet->getString(12));
		data.set_JLGLBH(resultSet->getString(13));
		data.set_JLCZZ(resultSet->getString(14));
		data.set_TROOPTYPE(resultSet->getString(15));
		data.set_LEVELTYPE(resultSet->getString(16));
		data.set_REASON(resultSet->getString(17));
		return data;
	}
};

#endif // !_MILITARYMAPPER_H_