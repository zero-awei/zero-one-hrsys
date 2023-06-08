#pragma once
/*
（人员花名册-人员花名册-分页查询员工数据）--洛洛
*/
#ifndef _EMPLOYEEPAGE_DAO_
#define _EMPLOYEEPAGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/RosterPersonDO.h"
#include "../../domain/query/RosterOfPer/EmployeePageQuery.h"

/**
 * 示例表数据库操作实现
 */
class EmployeePageDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const EmployeePageQuery::Wrapper& query);
	
	// 分页查询数据
	list<RosterPersonDO> selectWithPage(const EmployeePageQuery::Wrapper& query);

};
#endif // !_EMPLOYEEPAGE_DAO_
