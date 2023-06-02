#pragma once

#include "BaseDAO.h"
#include "../../domain/do/TerminationReminder/TerminationReminderDO.h"
#include "../../domain/query/TerminationReminder/TerminationReminderQuery.h"

/**
 * 示例表数据库操作实现
 */
class TerminationReminderDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const TerminationReminderQuery::Wrapper& query);
	// 分页查询数据
	list<TerminationReminderDO> selectWithPage(const TerminationReminderQuery::Wrapper& query);
	//查询全部
	list<TerminationReminderDO> selectAll(const TerminationReminderQuery::Wrapper& query);
};