#pragma once
/*
人员花名册-离退休人员-分页查询员工列表--pine
*/
#ifndef  _CHECK_RETIRES_LIST_MAPPER_
#define  _CHECK_RETIRES_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/RosterOfPer/RetiredEmployeesDO.h"

/**
 * 示例表字段匹配映射
 */
class CheckRetiresListMapper : public Mapper<RetiredEmployeesDO>
{
public:
	RetiredEmployeesDO mapper(ResultSet* resultSet) const override
	{
		RetiredEmployeesDO data;
		data.setygbh(resultSet->getUInt64(1));//this
		data.setpimpersonname(resultSet->getString(2));//this


		return data;
	}
};
#endif // !_SAMPLE_MAPPER_