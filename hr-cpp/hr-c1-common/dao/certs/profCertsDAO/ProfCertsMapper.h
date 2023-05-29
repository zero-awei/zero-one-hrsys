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
#ifndef _PROFCERTS_MAPPER_
#define _PROFCERTS_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/certs/ProfCertsDO.h"

/**
 * 职业资格证书类型下拉列表表字段匹配映射
 * 负责人 : rice
 */
class ProfCertsMapper : public Mapper<ProfCertsDO>
{
public:
	ProfCertsDO mapper(ResultSet* resultSet) const override
	{
		ProfCertsDO data;
		data.setPimQualMajorId(resultSet->getString(1));
		//cout << resultSet->getString(1) << endl;
		data.setPimQualMajorName(resultSet->getString(2));
		data.setCreateMan(resultSet->getString(3));
		data.setCreateDate(resultSet->getString(4));
		data.setEnable(resultSet->getInt(5));
		data.setUpDateMan(resultSet->getString(6));
		data.setUpDateDate(resultSet->getString(7));
		data.setPimQualTypeId(resultSet->getString(8));
		data.setOrmOrgId(resultSet->getString(9));
		data.setProfessionalType(resultSet->getString(10));
		data.setZyjszw(resultSet->getString(11));
		data.setQuaLevel(resultSet->getString(12));
		data.setQuaMajor(resultSet->getString(13));
		data.setGwlx(resultSet->getString(14));
		data.setGwType(resultSet->getString(15));
		data.setGwzs(resultSet->getString(16));
		data.setPimQualTypeName(resultSet->getString(17));
		return data;
	}
};

#endif // !_PROFCERTS_MAPPER_