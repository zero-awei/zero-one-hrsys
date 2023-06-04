#pragma once

#ifndef _TRAININGRECORD_DAO_
#define _TRAININGRECORD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/trainingrecord/TrainingRecordDO.h"
#include "../../domain/query/trainingrecord/TrainingRecordQuery.h"

/**
 * 示例表数据库操作实现
 */
class TrainingRecordDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const TrainingRecordPageQuery::Wrapper& query);
	// 分页查询数据
	list<TrainingRecordDO> selectWithPage(const TrainingRecordPageQuery::Wrapper& query);
};
#endif
