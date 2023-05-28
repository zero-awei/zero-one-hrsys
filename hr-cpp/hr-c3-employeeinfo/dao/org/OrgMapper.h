#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: J1senn
 @Date: 2022/10/25 14:21:55

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
#ifndef _ORG_MAPPER_
#define _ORG_MAPPER_

#include "Mapper.h"
#include "../../domain/do/org/OrgDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class OrgMapper : public Mapper<OrgDO>
{
public:
	OrgDO mapper(ResultSet* resultSet) const override
	{
		OrgDO data;
		data.setCompanyFlag(resultSet->getString(1));
		data.setOrgID(resultSet->getString(2));
		data.setOrgName(resultSet->getString(3));
		data.setPorgID(resultSet->getString(4));
		data.setPorgname(resultSet->getString(5));
		return data;
	}
};

#endif // !_ORG_MAPPER_