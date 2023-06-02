#pragma once
#ifndef _ContractInfo_MAPPER_
#define _ContractInfo_MAPPER_

#include "Mapper.h"
#include "domain/do/contractInfoakie/ContractInfoDO.h"

/**
 * 示例表字段匹配映射
 */
class ContractInfoMapper : public Mapper<ContractInfoDO>
{
public:
	ContractInfoDO mapper(ResultSet* resultSet) const override
	{
		ContractInfoDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setType(resultSet->getString(3));
		data.setVariety(resultSet->getString(4));
		data.setDate(resultSet->getString(5));
		data.setCondition(resultSet->getString(6));
		data.setDepartment_m(resultSet->getString(7));
		data.setDepartment_c(resultSet->getString(8));
		data.setTry_end(resultSet->getString(9));
		data.setTip(resultSet->getString(10));
		data.setInfoid(resultSet->getString(11));
		data.setDate_end(resultSet->getString(12));
		data.setContract_num(resultSet->getString(13));
		data.setEmp_condition(resultSet->getString(14));
		return data;
	}
};

#endif 