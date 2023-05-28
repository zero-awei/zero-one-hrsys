#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/27 21:39:27

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
#ifndef _LEGALENTITYMAIMAPPER_H_
#define _LEGALENTITYMAIMAPPER_H_

#include "Mapper.h"
#include "domain/do/LegalEntityMai/ormsignorgDO.h"

/* 法人主体维护字段匹配映射--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiMapper : public Mapper<OrmsignorgDO>
{
public:
	OrmsignorgDO mapper(ResultSet* resultSet) const override
	{
		OrmsignorgDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setCode(resultSet->getString(3));

		//data.setORMSIGNORGID(resultSet->getString(1));
		//data.setUPDATEMAN(resultSet->getString(2));
		//data.setCREATEMAN(resultSet->getString(3));
		//data.setCREATEDATE(resultSet->getString(4));
		//data.setORMSIGNORGNAME(resultSet->getString(5));
		//data.setUPDATEDATE(resultSet->getString(6));
		//data.setORGCODE(resultSet->getString(7));
		//data.setZZJC(resultSet->getString(8));
		return data;
	}
};

#endif // !_LEGALENTITYMAIMAPPER_H_