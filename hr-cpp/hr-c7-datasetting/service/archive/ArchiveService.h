#pragma once
#ifndef _ARCHIVE_SERVICE_
#define _ARCHIVE_SERVICE_
#include <list>
#include "domain/vo/archive/ArchiveVO.h"
#include "domain/query/archive/ArchiveQuery.h"
#include "domain/dto/archive/ArchiveDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ArchiveService
{
public:
	// 分页查询所有数据
	ArchivePageDTO::Wrapper listAll(const ArchiveQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ArchiveDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ArchiveDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_ARCHIVE_SERVICE_

