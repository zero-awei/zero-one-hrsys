#pragma once
/*
人员花名册-离退休人员-分页查询员工列表--pine
*/
#ifndef  _CHECK_RETIRES_LIST_MAPPER_
#define  _CHECK_RETIRES_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/RosterOfPer/RetiredEmployeesDO.h"

class CheckRetiresListMapper : public Mapper<RetiredEmployeesDO>
{
public:
	RetiredEmployeesDO mapper(ResultSet* resultSet) const override
	{
		RetiredEmployeesDO data;
		data.setygbh(resultSet->getString(1));//this
		data.setpimpersonname(resultSet->getString(2));//this
		data.setxb(resultSet->getString(3));//this
		data.setnj(resultSet->getString(4));//this
		data.setpostaladdress(resultSet->getString(5));//this
		data.setretiPlace(resultSet->getString(6));//this
		data.setjtlxr(resultSet->getString(7));//this
		data.setjtlxrdh(resultSet->getString(8));//this
		data.setzz(resultSet->getString(9));//this
		data.setbm(resultSet->getString(10));//this
		data.setrank(resultSet->getString(11));//this
		data.setyzw(resultSet->getString(12));//this
		data.setygw(resultSet->getString(13));//this
		data.settxdq(resultSet->getString(14));//this
		data.setsjtxrq(resultSet->getString(15));//this
		data.setlxdh(resultSet->getString(16));//this
		data.setspdylje(resultSet->getString(17));//this
		data.setpimpersonid(resultSet->getString(18));//this


		return data;
	}
};
#endif // !_CHECK_RETIRES_LIST_MAPPER_