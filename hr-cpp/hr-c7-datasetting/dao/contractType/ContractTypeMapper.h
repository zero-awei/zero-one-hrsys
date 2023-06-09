#pragma once
#ifndef _CONTRACTMAPPER_H_
#define _CONTRACTMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/ContractType/ContractTypeDO.h"

class ContractTypeMapper : public Mapper<ContractTypeDO>
{
public:
	ContractTypeDO mapper(ResultSet* resultSet) const override
	{
		ContractTypeDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_CONTRACTMAPPER_H_