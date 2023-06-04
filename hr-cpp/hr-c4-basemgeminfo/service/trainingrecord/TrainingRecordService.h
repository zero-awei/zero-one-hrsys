#pragma once

#ifndef _TRAININGRECORD_SERVICE_
#define _TRAININGRECORD_SERVICE_
#include <list>
#include "domain/vo/trainingrecord/TrainingRecordVO.h"
#include "domain/query/trainingrecord/TrainingRecordQuery.h"
#include "domain/dto/trainingrecord/TrainingRecordDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class TrainingRecordService
{
public:
	// 分页查询所有数据
	TrainingRecordPageDTO::Wrapper listAll(const TrainingRecordPageQuery::Wrapper& query);
};

#endif

