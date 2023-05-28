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
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setType(resultSet->getString(3));
		data.setVariety(resultSet->getString(4));
		data.setDate(resultSet->getString(5));
		data.setCondition(resultSet->getString(6));
		data.setDepartment_m(resultSet->getString(7));
		data.setDepartment_c(resultSet->getString(8));
		data.setDate_end(resultSet->getString(9));
		data.setTip(resultSet->getString(10));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_