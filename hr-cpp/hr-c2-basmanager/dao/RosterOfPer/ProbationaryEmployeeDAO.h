#pragma once
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/ProbationaryEmployeeDO.h"
#include "../../domain/query/RosterOfPer/ProbationaryEmployeeQuery.h"

/**
 * 人员花名册 - 试用人员数据库操作实现 - 楚孟献
 */
class ProbationaryEmployeeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ProbationaryEmployeeQuery::Wrapper& query);
	// 分页查询离职员工数据
	list<ProbationaryEmployeeDO> selectWithPage(const ProbationaryEmployeeQuery::Wrapper& query);
	// 分页查询离职员工数据
	list<ProbationaryEmployeeDO> selectAll(const ProbationaryEmployeeQuery::Wrapper& query);
	// 通过姓名查询数据
	list<ProbationaryEmployeeDO> selectByName(const string& name);
	// 通过编号查询数据
	list<ProbationaryEmployeeDO> selectById(const string& id);
};
#pragma once
