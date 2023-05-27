#pragma once
#ifndef _ARCHIVE_DAO_
#define _ARCHIVE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/archive/ArchiveDo.h"
#include "../../domain/query/archive/ArchiveQuery.h"

/**
 * 示例表数据库操作实现
 */
class ArchiveDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ArchiveQuery::Wrapper& query);
	// 分页查询数据
	list<ArchiveDO> selectWithPage(const ArchiveQuery::Wrapper& query);
	// 通过姓名查询数据
	list<ArchiveDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const ArchiveDO& iObj);
	// 修改数据
	int update(const ArchiveDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_ARCHIVE_DAO_
