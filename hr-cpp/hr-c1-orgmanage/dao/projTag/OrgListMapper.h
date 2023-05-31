#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/26 15:17:12

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
#ifndef _ORGLISTMAPPER_H_
#define _ORGLISTMAPPER_H_

#include "Mapper.h"
#include "domain/do/projTag/OrgListDO.h"

/**
 * 组织列表字段匹配映射
 * 负责人：Andrew
 */
class OrgListMapper : public Mapper<OrgListDO>
{
public:
	OrgListDO mapper(ResultSet* resultSet) const override
	{
		OrgListDO data;

		data.setCreateTime(resultSet->getString(1));
		data.setCreateby(resultSet->getString(2));
		data.setLevelCode(resultSet->getString(3));
		data.setOrgCode(resultSet->getString(4));
		data.setOrgId(resultSet->getString(5));
		data.setOrgName(resultSet->getString(6));
		data.setPorgId(resultSet->getString(7));
		data.setPorgName(resultSet->getString(8));
		data.setShortname(resultSet->getString(9));
		data.setUpdateTime(resultSet->getString(10));
		data.setUpdater(resultSet->getString(11));
		data.setOrgType(resultSet->getString(12));
		data.setBelongou(resultSet->getString(13));
		data.setBelongRegion(resultSet->getString(14));
		data.setOrgAddrCode(resultSet->getString(15));
		data.setOrgAddrOne(resultSet->getString(16));
		data.setOrgAddrTwo(resultSet->getString(17));
		data.setOrgCreateTime(resultSet->getString(18));
		data.setName(resultSet->getString(19));
		data.setRegionSubsidy(resultSet->getString(20));
		data.setErpOrgId(resultSet->getString(21));
		data.setSign(resultSet->getString(22));
		data.setCorrespondou(resultSet->getString(23));
		data.setFlag(resultSet->getString(24));

		return data;
	}
};

#endif // !_ORGLISTMAPPER_H_