#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/18 11:28:03

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
#ifndef _WORKHISTORYMAPPER_H_
#define _WORKHISTORYMAPPER_H_

#include "Mapper.h"
#include "domain/do/work-history/WorkHIstoryFindPageDO.h"


/**
 * ◊÷∂Œ∆•≈‰”≥…‰
 */
class WorkHistoryMapper : public Mapper<WorkHistoryFindDO>
{
public:
	WorkHistoryFindDO mapper(ResultSet* resultSet) const override
	{
		WorkHistoryFindDO data;
		data.setrZKSSJ(resultSet->getString(1));
		data.setrZJSSJ(resultSet->getString(2));
		data.setoRMORGNAME(resultSet->getString(3));
		data.setoRMORGNAME(resultSet->getString(4));
		data.setoRMDUTYNAME(resultSet->getString(5));
		data.setoRMPOSTNAME(resultSet->getString(6));
		data.setcFPLX(resultSet->getString(7));
		data.seteXPERIENCE(resultSet->getInt(8));
		data.setpIMWORKHISTORYID(resultSet->getString(9));
		data.setpIMPERSONID(resultSet->getString(10));
		return data;
	}
};

#endif // !_WORKHISTORYMAPPER_H_