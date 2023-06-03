#pragma once

#ifndef _PAPER_SERVICE_
#define _PAPER_SERVICE_
#include <list>
#include "domain/vo/paperinfo/PaperVO.h"
#include "domain/query/paperinfo/PaperQuery.h"
#include "domain/dto/paperinfo/PaperinfoDTO.h"

/**
 * 论文信息服务实现
 */
class PaperService
{
public:
	// 查询指定论文信息详情
	PaperinfoDTO::Wrapper listAll(const string& st);
	// 修改数据
	bool updateData(const ModifyPaperinfoDTO::Wrapper& dto);
};

#endif // !_PAPER_SERVICE_

