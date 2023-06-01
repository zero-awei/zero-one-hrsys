#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xubuxi
 @Date: 2023/05/31 1:15:33

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
#ifndef _PAGEQUERYBZMAPPER_H_
#define _PAGEQUERYBZMAPPER_H_

#include "Mapper.h"
#include "domain/do/orgbz/PageQueryBzDO.h"
#include "domain/query/orgbz/PageBzQuery.h"

class PageQueryBzMapper : public Mapper<PageQueryBzDO>
{
public:
	PageQueryBzDO mapper(ResultSet* resultSet) const override
	{
		PageQueryBzDO data;

		data.setOrgId(resultSet->getString(1));
		data.setOrgName(resultSet->getString(2));
		data.setOrgSectorId(resultSet->getString(3));
		data.setOrgSectorName(resultSet->getString(4));
		data.setOrgCode(resultSet->getString(5));
		data.setSectorType(resultSet->getString(6));
		data.setCreateBy(resultSet->getString(7));
		data.setCreateTime(resultSet->getString(8));
		data.setUpdateBy(resultSet->getString(9));
		data.setUpdateTime(resultSet->getString(10));
		data.setBzrs(resultSet->getString(11));
		data.setSjbzrs(resultSet->getString(12));

		return data;
	}
};
#endif // !_PAGEQUERYBZMAPPER_H_