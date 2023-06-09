#pragma once
#ifndef _ARCHIVES_DAO_
#define _ARCHIVES_DAO_
#include "BaseDAO.h"
#include "../../domain/do/archives/t_pimarchivesDO.h"
#include "../../domain/query/archives/ArchivesQuery.h"

/**
 * 示例表数据库操作实现
 */
class ArchivesDAO : public BaseDAO
{
public:
	// 查询详细数据
	// asd
	list<t_pimarchivesDO> selectAll(const ArchivesQuery::Wrapper& query);
	// 统计数据条数
	uint64_t count(const ArchivesQuery::Wrapper& query);
	// 分页查询数据
	list<t_pimarchivesDO> selectWithPage(const ArchivesQuery::Wrapper& query);
	// 插入数据 
	uint64_t insert(const t_pimarchivesDO& iObj, uint64_t id);
	// 通过ID删除数据
	int deleteById(const string& id);
};
#endif // !_ARCHIVES_DAO_
