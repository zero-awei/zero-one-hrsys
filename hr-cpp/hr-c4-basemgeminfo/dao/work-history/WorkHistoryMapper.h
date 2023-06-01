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
#include "../../domain/do/work-history/ModWorkHistoryDO.h"

/**
 * ◊÷∂Œ∆•≈‰”≥…‰
 */
class WorkHistoryPageMapper : public Mapper<WorkHistoryFindDO>
{
public:
	WorkHistoryFindDO mapper(ResultSet* resultSet) const override
	{
		WorkHistoryFindDO data;
		
		data.setrZKSSJ(resultSet->getString(1));
		data.setrZJSSJ(resultSet->getString(2));
		data.setoRMORGNAME(resultSet->getString(3));
		data.setoRMORGSECTORNAME(resultSet->getString(4));
		data.setoRMDUTYNAME(resultSet->getString(5));
		data.setoRMPOSTNAME(resultSet->getString(6));
		data.setcFPLX(resultSet->getString(7));
		data.seteXPERIENCE(resultSet->getInt(8));
		data.setpIMWORKHISTORYID(resultSet->getString(9));
		data.setpIMPERSONID(resultSet->getString(10));
		//data.setoRMORGSECTORNAME(resultSet->getString(11));
		return data;
	}
};



class WorkHistoryMapper : public Mapper<WorkHistoryDO>
{
public:
	WorkHistoryDO mapper(ResultSet* resultSet) const override
	{
		WorkHistoryDO data;
		data.setRzkssj(resultSet->getString(1));
		data.setRzjssj(resultSet->getString(2));
		data.setOrmorgname(resultSet->getString(3));
		data.setOrmorgsectorname(resultSet->getString(4));
		data.setOrmdutyname(resultSet->getString(5));
		data.setOrmpostname(resultSet->getString(6));
		data.setCfplx(resultSet->getString(7));
		data.setExperience(resultSet->getUInt64(8));
		data.setPimpersonid(resultSet->getString(9));
		data.setUpdatedate(resultSet->getString(10));
		data.setUpdateman(resultSet->getString(11));
		data.setPimworkhistoryid(resultSet->getString(12));
		
		return data;
	}
};
class ModWorkHistoryMapper : public Mapper<ModWorkHistoryDO>
{
public:
	ModWorkHistoryDO mapper(ResultSet* resultSet) const override
	{
		ModWorkHistoryDO data;
		data.setRzkssj(resultSet->getString(1));
		data.setRzjssj(resultSet->getString(2));
		data.setOrmorgname(resultSet->getString(3));
		data.setOrmorgsectorname(resultSet->getString(4));
		data.setOrmdutyname(resultSet->getString(5));
		data.setOrmpostname(resultSet->getString(6));
		data.setCfplx(resultSet->getString(7));
		data.setExperience(resultSet->getUInt64(8));
		data.setPimpersonid(resultSet->getString(9));
		data.setPimworkhistoryid(resultSet->getString(10));
		data.setUpdatedate(resultSet->getString(11));
		data.setUpdateman(resultSet->getString(12));

		return data;
	}
};



#endif // !_WORKHISTORYMAPPER_H_
