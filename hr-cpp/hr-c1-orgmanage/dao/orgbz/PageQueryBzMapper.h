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

		data.setOrgname(resultSet->getString(1));
		data.setOrgid(resultSet->getString(2));
		data.setOrgsectorname(resultSet->getString(3));
		data.setOrgcode(resultSet->getString(4));
		data.setJhry(resultSet->getString(5));
		data.setSjry(resultSet->getString(6));


		return data;
	}
};
#endif // !_PAGEQUERYBZMAPPER_H_