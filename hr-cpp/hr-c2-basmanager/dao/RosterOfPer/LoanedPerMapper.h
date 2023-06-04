#pragma once
#ifndef _LOANEDPER_MAPPER_
#define _LOANEDPER_MAPPER_
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
		data.setPIMDISTIRBUTIONID(resultSet->getString(1));
		data.setpimPersonName(resultSet->getString(2));
		data.setygbh(resultSet->getString(3));
		data.setyzw(resultSet->getString(4));
		data.setbm(resultSet->getString(5));
		data.setyzw(resultSet->getString(6));
		data.setygw(resultSet->getString(7));
		data.setormName(resultSet->getString(8));
		data.setormOrgSectorName(resultSet->getString(9));
		data.setormDutyName(resultSet->getString(10));
		data.setormPostName(resultSet->getString(11));
		data.setpcmydjdmxId(resultSet->getString(12));
		data.setjdksrq(resultSet->getString(13));
		data.setjdjsrq(resultSet->getString(14));
		return data;			   
	}							   
};								   
#endif // !_LOANEDPER_MAPPER_	   
