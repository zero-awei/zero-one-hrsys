#pragma once
#ifndef _T_PIMARCHIVES_DAO_
#define _T_PIMARCHIVES_DAO_
#include "BaseDAO.h"
#include "../../domain/do/t_pimarchives/t_pimarchivesDO.h"
#include "../../domain/query/EmployeeNotInArchive/EmployeeNotInArchiveQuery.h"

class t_pimarchivesDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const EmployeeNotInArchiveQuery::Wrapper& query);
	// 分页查询数据
	list<t_pimarchivesDO> selectWithPage(const EmployeeNotInArchiveQuery::Wrapper& query);
	// 调入档案
	int update(const t_pimarchivesDO& uObj);
};

#endif // !_T_PIMARCHIVES_DAO_