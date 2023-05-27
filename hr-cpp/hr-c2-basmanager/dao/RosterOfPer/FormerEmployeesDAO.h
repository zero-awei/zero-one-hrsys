#pragma once

#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/FormerEmployeesDO.h"
#include "../../domain/query/RosterOfPer/FormerEmployeesQuery.h"

/**
 * 离职人员数据库操作实现
 */
class FormerEmployeesDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const FormerEmployeesQuery::Wrapper& query);
	// 分页查询离职员工数据
	list<FormerEmployeesDO> selectWithPage(const FormerEmployeesQuery::Wrapper& query);
	// 通过姓名查询数据
	list<FormerEmployeesDO> selectByName(const string& name);
	// 通过编号查询数据
	list<FormerEmployeesDO> selectById(const string& id);
};
