#pragma once
#ifndef _LoanedPer_MAPPER_
#define _LoanedPer_MAPPER_
#include "Mapper.h"
#include "../../domain/do/RosterOfPer/SecondedPersonnelDO.h"
/**
 * 借调人员表字段匹配映射--(人员花名册-借调人员-分页查询员工列表)--luoluo
 */
class LoanedPerMapper :public Mapper<SecondedPersonnelDO>
{
public:
	SecondedPersonnelDO mapper(ResultSet* resultSet) const override
	{
		SecondedPersonnelDO data;
		data.setygbh(resultSet->getString(1));
		data.setpimPersonName(resultSet->getString(2));
		data.setzz(resultSet->getString(3));
		data.setbm(resultSet->getString(4));
		data.setyzw(resultSet->getString(5));
		data.setygw(resultSet->getString(6));
		data.setormName(resultSet->getString(7));
		data.setormOrgSectorName(resultSet->getString(8));
		data.setormDutyName(resultSet->getString(9));
		data.setormPostName(resultSet->getString(10));
		data.setpcmydjdmxId(resultSet->getString(11));
		data.setjdksrq(resultSet->getString(12));
		data.setjdjsrq(resultSet->getString(13));
		return data;
	}
};
#endif // !_LoanedPer_MAPPER_
