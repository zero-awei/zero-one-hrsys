#pragma once
#ifndef _ARCHIVES_DAO_
#define _ARCHIVES_DAO_
#include "BaseDAO.h"
#include "../../domain/do/archives/archivesinfoDO.h"
#include "../../domain/do/archivesCenter/archivesCenterDO.h"
#include "../../domain/query/archivesCenter/ArchivesCenterQuery.h"
#include "../../domain/do/UpdateArchiveInfo/UpdateArchiveInfoDO.h"
#include "../../service/archives/ArchivesService.h"

class ArchivesCenterDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ArchivesCenterQuery::Wrapper& query);
	// 分页查询档案室
	list<archivesCenterDO> selectWithPage(const ArchivesCenterQuery::Wrapper& query);
};

class ArchivesDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ArchivesCenterQuery::Wrapper& query);
	// 查询指定档案详情 在service实现了getAll函数
	list<archivesinfoDO> selectAll(const ArchivesQuery::Wrapper& query);
	// 更新指定档案
	int update(const archivesinfoDO& uObj);
};

#endifclass ArchivesDAO : public BaseDAO
{
public:
	// 查询详细数据
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
