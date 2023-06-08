#pragma once
#ifndef _GOSH_MAPPER_
#define _GOSH_MAPPER_

#include "Mapper.h"
#include "domain/do/Gosh/ContractDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class GoshMapper : public Mapper<ContractDO>
{
public:
	ContractDO mapper(ResultSet* resultSet) const override
	{
		ContractDO data;
		data.setPersonid(resultSet->getString(1));
		data.setId(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setType(resultSet->getString(4));
		data.setVariety(resultSet->getString(5));
		data.setDate(resultSet->getString(6));
		data.setCondition(resultSet->getString(7));
		data.setDepartment_c(resultSet->getString(8));
		data.setDate_end(resultSet->getString(9));
		data.setPerson_department(resultSet->getString(10));
		data.setPerson_condition(resultSet->getString(11));
		data.setDate_arrive(resultSet->getString(12));
		data.setDate_over(resultSet->getString(13));
		data.setRest(resultSet->getString(14));
		return data;
	}
};

class GoshMapper_contract : public Mapper<ContractDO>
{
public:
	ContractDO mapper(ResultSet* resultSet) const override
	{
		ContractDO data;
		data.setPersonid(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setPerson_condition(resultSet->getString(3));
		data.setId(resultSet->getString(4));
		data.setType(resultSet->getString(5));
		data.setCondition(resultSet->getString(6));
		data.setDate(resultSet->getString(7));
		data.setDate_over(resultSet->getString(8));
		data.setDepartment_c(resultSet->getString(8));
		data.setVariety(resultSet->getString(9));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_