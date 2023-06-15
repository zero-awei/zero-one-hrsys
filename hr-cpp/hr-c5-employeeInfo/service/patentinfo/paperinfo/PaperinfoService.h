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
	PaperPageDTO::Wrapper listAll(const PaperQuery::Wrapper& query);
	// 保存数据
	// int 影响数据行数
	int saveData(const PaperDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(string id);
	// 查询数据ID
	uint64_t selectPaperID(const PaperDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

