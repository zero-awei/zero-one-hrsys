#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _PROBATIONARY_EMPLOYEE_MAPPER_
#define _PROBATIONARY_EMPLOYEE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/RosterOfPer/ProbationaryEmployeeDO.h"

/**
 * 人员花名册 - 试用员工 - 试用员工详情表字段匹配映射 - 楚孟献
 */
class ProbationaryEmployeeMapper : public Mapper<ProbationaryEmployeeDO>
{
public:
	ProbationaryEmployeeDO mapper(ResultSet* resultSet) const override
	{
		ProbationaryEmployeeDO data;
		data.setYGBH(resultSet->getString(1));
		data.setPIMPERSONNAME(resultSet->getString(2));
		data.setORMORGNAME(resultSet->getString(3));
		data.setORMORGSECTORNAME(resultSet->getString(4));
		data.setZW(resultSet->getString(5));
		data.setORMPOSTNAME(resultSet->getString(6));
		data.setRZSJ(resultSet->getString(7));
		data.setSYDQ(resultSet->getString(8));
		return data;
	}
};

#endif 