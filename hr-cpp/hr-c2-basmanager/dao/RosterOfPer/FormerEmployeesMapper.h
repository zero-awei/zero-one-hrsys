#pragma once

#ifndef _FORMER_EMPLOYEES_MAPPER_
#define _FORMER_EMPLOYEES_MAPPER_

#include "Mapper.h"
#include "../../domain/do/RosterOfPer/FormerEmployeesDO.h"

/**
 * 离职人员表字段匹配映射- 楚孟献
 */
class FormerEmployeesMapper :public Mapper<FormerEmployeesDO>
{
public:
	FormerEmployeesDO mapper(ResultSet* resultSet) const override
	{
		FormerEmployeesDO data;
		
		data.setpimPersonId(resultSet->getString(13));
		data.setygbh(resultSet->getString(2));
		data.setpimPersonName(resultSet->getString(3));
		data.setsex(resultSet->getString(4));
		data.setlxdh(resultSet->getString(5));
		data.setcsrq(resultSet->getString(6));
		data.setorganizationName(resultSet->getString(7));
		data.setbm(resultSet->getString(8));
		data.setpostalAddress(resultSet->getString(9));
		data.setjtlxr(resultSet->getString(10));
		data.setjtlxrdh(resultSet->getString(11));
		data.setrank(resultSet->getString(12));
		return data;
	}
};

#endif