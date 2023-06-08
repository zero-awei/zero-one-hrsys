#pragma once
#ifndef _ARCHIVESDAO_H_
#define _ARCHIVESDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/archives/ArchivesDO.h"
#include "../../domain/query/archives/ArchivesQuery.h"

class ArchivesDAO : public BaseDAO {
public:
	//统计有多少条数据
	uint64_t count(const ArchivesQuery::Wrapper& query);
	// 分页查询数据
	list<ArchivesDO> selectWithPage(const ArchivesQuery::Wrapper& query);
};

#endif // !_ARCHIVESDAO_H_