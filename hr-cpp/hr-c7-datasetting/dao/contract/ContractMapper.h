#pragma once
#ifndef _CONTRACTMAPPER_H_
#define _CONTRACTMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/contractType/ContractTypeDO.h"

class ContractMapper : public Mapper<ContractDO>
{
public:
	ContractDO mapper(ResultSet* resultSet) const override
	{
		ContractDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setDepartment(resultSet->getString(3));
		data.setState(resultSet->getString(4));
		data.setUnitArrivalTime(resultSet->getString(5));
		data.setContractId(resultSet->getString(6));
		data.setSigningUnit(resultSet->getString(7));
		data.setContract_category(resultSet->getString(8));
		data.setContract_type(resultSet->getString(9));
		data.setStartDate(resultSet->getString(10));
		data.setEndDate(resultSet->getString(11));
		data.setContractStatus(resultSet->getString(12));
		data.setRemainingDays(resultSet->getString(13));
		data.setExpiryDate(resultSet->getString(14));
		return data;
	}
};

#endif // !_CONTRACTMAPPER_H_