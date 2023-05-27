#pragma once
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/ProbationaryEmployeeDO.h"
#include "../../domain/query/RosterOfPer/ProbationaryEmployeeQuery.h"

/**
 * 离职人员数据库操作实现
 */
class ProbationaryEmployeeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ProbationaryEmployeeQuery::Wrapper& query);
	// 分页查询离职员工数据
	list<ProbationaryEmployeeDO> selectWithPage(const ProbationaryEmployeeQuery::Wrapper& query);
	// 通过姓名查询数据
	list<ProbationaryEmployeeDO> selectByName(const string& name);
	// 通过编号查询数据
	list<ProbationaryEmployeeDO> selectById(const string& id);
};
#pragma once
