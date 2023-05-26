#pragma once
#ifndef _EMPLOYEEINFO_DAO_
#define _EMPLOYEEINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CertificateManage/EmployeeInfoDO.h"
#include "../../domain/query/CertificateManage/EmployeeInfoQuery.h"

/**
 * 人员信息分页查询DAO--(证书管理-分页查询员工信息列表)--weixiaoman
 */
class EmployeeInfoDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const EmployeeInfoQuery::Wrapper& query);
	// 分页查询数据
	list<EmployeeInfoDO> selectWithPage(const EmployeeInfoQuery::Wrapper& query);
	// 根据名字查询
	list<EmployeeInfoDO> selectByName(const string& name);
};
#endif // !_EMPLOYEEINFO_DAO_