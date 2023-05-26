#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: mengHuan
 @Date: 2023/05/25 21:45:28

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
#ifndef _LABORDISPATCHMAPPER_H_
#define _LABORDISPATCHMAPPER_H_
#include "Mapper.h"
#include "domain/do/laborDispatch/LaborDispatchDO.h"


class LaborDispatchMapper : public Mapper<LaborDispatchDO>
{
public:
	LaborDispatchDO mapper(ResultSet* resultSet) const override
	{
		LaborDispatchDO data;
		data.setName(resultSet->getString(1));
		data.setId(resultSet->getString(2));
		data.setCreatedate(resultSet->getString(3));
		data.setCreateman(resultSet->getString(4));
		data.setUpdatedate(resultSet->getString(5));
		data.setJyfw(resultSet->getString(6));
		data.setLxdz(resultSet->getString(7));
		data.setLxfs(resultSet->getString(8));
		data.setLxr(resultSet->getString(9));
		data.setGsjj(resultSet->getString(10));
		data.setPimpersonid(resultSet->getString(11));
		data.setOrmorgid(resultSet->getString(12));
		data.setRegcapital(resultSet->getString(13));
		data.setLegalperson(resultSet->getString(14));
		return data;
	}
};

#endif // !_LABORDISPATCHMAPPER_H_