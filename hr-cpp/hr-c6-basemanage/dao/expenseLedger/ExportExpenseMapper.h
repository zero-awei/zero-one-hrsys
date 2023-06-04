#pragma once
#ifndef _EXPORTEXPENSE_MAPPER_
#define _EXPORTEXPENSE_MAPPER_
#include "Mapper.h"
#include "domain/do/expenseLedger/ExpenseLedgerDO.h"

class ExportExpenseMapper : public Mapper<ExpenseLedgerDO>
{
public:
	ExpenseLedgerDO mapper(ResultSet* resultSet) const override
	{
		ExpenseLedgerDO data;
		data.setFylb(resultSet->getString(1));
		data.setFyje(resultSet->getDouble(2));
		data.setFfrs(resultSet->getInt(3));
		data.setFfsj(resultSet->getString(4));
		data.setFybz(resultSet->getString(5));
		data.setBz(resultSet->getString(6));
		return data;
	}
};
#endif