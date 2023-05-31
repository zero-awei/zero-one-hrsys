#pragma once
#ifndef  _RETIREMENTMAPPER_H_
#define  _RETIREMENTMAPPER_H_

#include "Mapper.h"
#include "domain/do/retirement/retirementDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class RetirementMapper : public Mapper<retirementDO>
{
public:
	retirementDO mapper(ResultSet* resultSet) const override
	{
		retirementDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getString(4));
		data.setMailing_address(resultSet->getString(5));
		data.setRetire_address(resultSet->getString(6));
		data.setFamily_Contact(resultSet->getString(7));
		data.setOrganization(resultSet->getString(8));
		data.setDepartment(resultSet->getString(9));
		data.setRank(resultSet->getString(10));
		data.setBefore_retire_rank(resultSet->getString(11));
		data.setBefore_retire_post(resultSet->getString(12));
		data.setRetire_time(resultSet->getString(13));
		data.setRead_retire_time(resultSet->getString(14));
		data.setTel(resultSet->getString(15));
		data.setApproved_Pension_amount(resultSet->getString(16));
		return data;
	}
};


#endif // ! _RETIREMENTMAPPER_H_
