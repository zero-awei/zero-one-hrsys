#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 14:08:32

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
#ifndef _CONTRACTMAPPER_H_
#define _CONTRACTMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/contract/ContractDO.h"

class ContractMapper : public Mapper<ContractDO>
{
public:
	ContractDO mapper(ResultSet* resultSet) const override
	{
		ContractDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setUnit(resultSet->getString(3));
		data.setState(resultSet->getString(4));
		data.setUnitTime(resultSet->getString(5));
		data.setContractID(resultSet->getString(6));
		data.setContractUnit(resultSet->getString(7));
		data.setContractCategory(resultSet->getString(8));
		data.setContractType(resultSet->getString(9));
		data.setStartDate(resultSet->getString(10));
		data.setEndDate(resultSet->getString(11));
		data.setContractStatus(resultSet->getString(12));
		data.setRemaining(resultSet->getString(13));
		data.setTrialExpiration(resultSet->getString(14));
		return data;
	}
};

#endif // !_CONTRACTMAPPER_H_