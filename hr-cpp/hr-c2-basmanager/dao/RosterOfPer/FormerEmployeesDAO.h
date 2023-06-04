#pragma once
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/FormerEmployeesDO.h"
#include "../../domain/query/RosterOfPer/FormerEmployeesQuery.h"

/**
 * 人员花名册 - 离职人员数据库操作实现 - 楚孟献
 */

class FormerEmployeesDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const FormerEmployeesQuery::Wrapper& query);
	// 分页查询离职员工数据
	list<FormerEmployeesDO> selectWithPage(const FormerEmployeesQuery::Wrapper& query);
	// 查询离职员工数据
	list<FormerEmployeesDO> selectAll(const FormerEmployeesQuery::Wrapper& query);
};
