#pragma once

#ifndef _TEMPORARYSTAFF_MAPPER_
#define _TEMPORARYSTAFF_MAPPER_
#include "Mapper.h"
#include "../../domain/do/RosterOfPer/TemporaryStaffDO.h"
/**
 * 挂职人员表字段匹配映射
 */
class TempStaffMapper :public Mapper<TemporaryStaffDO>
{
public:
	TemporaryStaffDO mapper(ResultSet* resultSet) const override
	{
		TemporaryStaffDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setEmpStatus(resultSet->getString(3));
		data.setTempStatus(resultSet->getString(4));
		data.setTempOrg(resultSet->getString(5));
		data.setTempDept(resultSet->getString(6));
		data.setTempStartTime(resultSet->getString(7));
		data.setTempEndTime(resultSet->getString(8));
		return data;
	}
};
#endif // !_TEMPORARYSTAFF_MAPPER_
