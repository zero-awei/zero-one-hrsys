#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: rice
 @Date: 2023/5/24 14:30:55

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
#ifndef _CERTTYPE_MAPPER_
#define _CERTTYPE_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/certs/CertTypeDO.h"

/**
 * 证书类型下拉列表表字段匹配映射
 * 负责人 : rice
 */
class CertTypeMapper : public Mapper<CertTypeDO>
{
public:
	CertTypeDO mapper(ResultSet* resultSet) const override
	{
		CertTypeDO data;
		data.setCertTypeId(resultSet->getString(1));
		data.setCertTypeName(resultSet->getString(2));
		data.setCertTypeCode(resultSet->getString(3));
		data.setCertTypeValidity(resultSet->getInt(4));
		return data;
	}
};

#endif // !_CERTTYPE_MAPPER_