#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2023/05/25 8:19:29

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
#ifndef _EMPLOYEEINFOMAPPER_H_
#define _EMPLOYEEINFOMAPPER_H_

#include"Mapper.h"
#include"../../domain/do/employeeInfo/EmployeeInfoDO.h"

class EmployeeInfoMapper : public Mapper<EmployeeInfoDO>
{
public:
	EmployeeInfoDO mapper(ResultSet* res) const override
	{
		EmployeeInfoDO data;
		data.setId(res->getString(1));
		data.setName(res->getString(2));
		data.setIdType(res->getString(3));
		data.setIdNum(res->getString(4));
		data.setBirthday(res->getString(5));
		data.setAge(res->getUInt(6));
		data.setSex(res->getString(7));
		data.setNation(res->getString(8));
		data.setNative(res->getString(9));
		data.setMarriage(res->getString(10));
		data.setPolitic(res->getString(11));
		data.setRank(res->getString(12));
		data.setWorkTime(res->getString(13));
		data.setInTime(res->getString(14));
		data.setEmail(res->getString(15));
		data.setTechTitle(res->getString(16));
		data.setAcaCredit(res->getString(17));
		data.setFirAcaCredit(res->getString(18));
		data.setPracCerfigicate(res->getString(19));
		data.setPhoto(res->getString(20));
		data.setPhone(res->getString(21));
		return data;
	}
};

#endif // !_EMPLOYEEINFOMAPPER_H_