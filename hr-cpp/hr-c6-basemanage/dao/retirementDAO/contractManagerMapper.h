#pragma once
#ifndef _CONTRACTMANAGERMAPPER_H_
#define _CONTRACTMANAGERMAPPER_H_


#include "Mapper.h"
#include "domain/do/retirement/contractManagerDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class contractManagerMapper : public Mapper<contractManagerDO>
{
public:
	contractManagerDO mapper(ResultSet* resultSet) const override
	{
		contractManagerDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setEmployee_Unit(resultSet->getString(3));
		data.setEmployee_state(resultSet->getString(4));
		data.setTime_Unit(resultSet->getString(5));
		data.setContract_id(resultSet->getString(6));
		data.setContract_Unit(resultSet->getString(7));
		data.setClass_Contract(resultSet->getString(8));
		data.setcontract_Type(resultSet->getString(9));
		data.setStart_date(resultSet->getString(10));
		data.setStop_date(resultSet->getString(11));
		data.setOperation_Column(resultSet->getString(12));
		return data;
	}
};

#endif // !_CONTRACTMANAGERMAPPER_H_
