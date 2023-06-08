#pragma once

#include "Mapper.h"
#include "../../domain/do/TerminationReminder/TerminationReminderDO.h"

/**
 * Ê¾Àı±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class TerminationReminderMapper : public Mapper<TerminationReminderDO>
{
public:
	TerminationReminderDO mapper(ResultSet* resultSet) const override
	{
		TerminationReminderDO data;
		data.setArrivedTime(resultSet->getString(5));
		data.setBeginTime(resultSet->getString(10));
		data.setContractId(resultSet->getString(6));
		data.setContractLB(resultSet->getString(8));
		data.setContractLX(resultSet->getString(9));
		data.setContractSignPart(resultSet->getString(7));
		data.setDeadline(resultSet->getString(11));
		data.setEmployeeId(resultSet->getString(1));
		data.setEmployeeName(resultSet->getString(2));
		data.setEmployeePart(resultSet->getString(3));
		data.setEmployeeStatus(resultSet->getString(4));
		//data.setId(resultSet->getUInt64(1));
		//data.setName(resultSet->getString(2));
		//data.setSex(resultSet->getString(3));
		//data.setAge(resultSet->getInt(4));
		return data;
	}
};
