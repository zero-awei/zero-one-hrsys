#pragma once

#ifndef _ARCHIVES_SERVICE_
#define _ARCHIVES_SERVICE_
#include <list>
#include "domain/vo/archives/ArchivesVO.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/dto/archives/ArchivesDTO.h"
#include "domain/dto/archives/ArchivesDelDTO.h"
#include "domain/vo/archives/ArchivesDelVO.h"

/**
 * 服务实现
 */
class ArchivesService
{
public:
	// 查询详细信息
	ArchivesPageDTO::Wrapper getAll(const ArchivesQuery::Wrapper& query);
	// 分页查询所有数据
	ArchivesPageDTO::Wrapper listAll(const ArchivesQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ArchivesDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const ArchivesDelDTO::Wrapper& dto);
};

#endif // !_ARCHIVES_SERVICE_

