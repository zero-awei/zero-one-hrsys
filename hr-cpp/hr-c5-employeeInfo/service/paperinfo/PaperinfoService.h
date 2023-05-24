#pragma once

#ifndef _PAPERINFO_SERVICE_
#define _PAPERINFO_SERVICE_
#include <list>
#include "domain/vo/paperinfo/PaperVO.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/dto/paperinfo/PaperDTO.h"

/**
 * 论文信息服务实现
 */
class PaperinfoService
{
public:
	// 分页查询所有数据
	PaperPageDTO::Wrapper listByPimpersonId(const PaperQuery::Wrapper& query);
	// 修改数据
	bool updateData(const PaperDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

