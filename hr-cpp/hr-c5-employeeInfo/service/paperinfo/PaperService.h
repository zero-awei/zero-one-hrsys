#pragma once

#ifndef _PAPER_SERVICE_
#define _PAPER_SERVICE_
#include <list>
#include "domain/vo/paperinfo/PaperVO.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/dto/paperinfo/PaperDTO.h"

/**
 * 论文信息服务实现
 */
class PaperService
{
public:
	// 查询指定论文信息详情
	PaperDTO::Wrapper listAll(const string& st);
	// 修改数据
	bool updateData(const PaperDTO::Wrapper& dto);
};

#endif // !_PAPER_SERVICE_

