#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/31 0:50:35

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
#ifndef _LEGALENTITYSETMAPPER_H_
#define _LEGALENTITYSETMAPPER_H_

#include "Mapper.h"
#include "domain/do/LegalEntitySet/QueryLegalEntitySetDO.h"

/* 法人主体设置字段匹配映射--（组织管理-数据设置-法人主体设置）--TripleGold */
class LegalEntitySetMapper : public Mapper<QueryLegalEntitySetDO>
{
public:
	QueryLegalEntitySetDO mapper(ResultSet* resultSet) const override
	{
		QueryLegalEntitySetDO data;
		data.setId(resultSet->getString(1));
		data.setOrgName(resultSet->getString(2));
		data.setLEMName(resultSet->getString(3));
		data.setDefa(resultSet->getString(4));
		return data;
	}
};

#endif // !_LEGALENTITYSETMAPPER_H_