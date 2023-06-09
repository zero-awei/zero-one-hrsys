#pragma once
#ifndef _CONTRACTCATEGORYMAPPER_H_
#define _CONTRACTCATEGORYMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/contractcategory/ContractCategoryDO.h"

/**
 * 
 */
class ContractCategoryMapper : public Mapper<ContractCategoryDO>
{
public:
    ContractCategoryDO mapper(ResultSet* resultSet) const override
    {
        ContractCategoryDO data;
        data.setId(resultSet->getString("PIMCONTRACTTYPEID"));
        data.setName(resultSet->getString("PIMCONTRACTTYPENAME"));
        return data;
    }
};

#endif // _CONTRACT_CATEGORY_MAPPER_H_

