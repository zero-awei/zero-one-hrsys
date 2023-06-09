#pragma once

#ifndef _J_PAPER_SERVICE_
#define _J_PAPER_SERVICE_
#include <list>
#include "domain/vo/J_paperinfo/J_PaperVO.h"
#include "domain/dto/J_paperinfo/J_PaperinfoDTO.h"

/**
 * 论文信息服务实现
 */
class PaperService
{
public:
	// 查询指定论文信息详情
	J_PaperinfoDTO::Wrapper listAll(const string& st);
	// 修改数据
	bool updateData(const ModifyPaperinfoDTO::Wrapper& dto);
};

#endif // !_PAPER_SERVICE_

