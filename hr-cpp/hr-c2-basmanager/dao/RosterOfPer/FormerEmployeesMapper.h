#pragma once

#ifndef _FORMER_EMPLOYEES_MAPPER_
#define _FORMER_EMPLOYEES_MAPPER_

#include "Mapper.h"
#include "../../domain/do/RosterOfPer/FormerEmployeesDO.h"

/**
 * 离职人员表字段匹配映射
 */
class FormerEmployeesMapper :public Mapper<FormerEmployeesDO>
{
public:
	FormerEmployeesDO mapper(ResultSet* resultSet) const override
	{
		FormerEmployeesDO data;
		data.setygbh(resultSet->getString(1));
		data.setpimPersonName(resultSet->getString(2));
		data.setsex(resultSet->getString(3));
		data.setlxdh(resultSet->getString(4));
		data.setcsrq(resultSet->getString(5));
		data.setorganizationName(resultSet->getString(6));
		data.setbm(resultSet->getString(7));
		data.setrank(resultSet->getString(8));
		data.setpostalAddress(resultSet->getString(8));
		data.setjtlxr(resultSet->getString(8));
		data.setjtlxrdh(resultSet->getString(8));
		return data;
	}
};

#endif