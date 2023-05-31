#pragma once
#ifndef _EMPLOYEEINFO_MAPPER_
#define _EMPLOYEEINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CertificateManage/EmployeeInfoDO.h"

/**
 * 人员信息分页查询Mapper--(证书管理-分页查询员工信息列表)--weixiaoman
 */
class EmployeeInfoMapper : public Mapper<EmployeeInfoDO>
{
public:
	EmployeeInfoDO mapper(ResultSet* resultSet) const override
	{
		EmployeeInfoDO data;
		data.setName(resultSet->getString(1));
		data.setId(resultSet->getString(2));
		return data;
	}
};

#endif // !_EMPLOYEEINFO_MAPPER_