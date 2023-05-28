#pragma once
#ifndef _T_PIMARCHIVES_DAO_
#define _T_PIMARCHIVES_DAO_
#include "BaseDAO.h"
#include "../../domain/do/t_pimarchives/t_pimarchivesDO.h"
#include "../../domain/query/EmployeeNotInArchive/EmployeeNotInArchiveQuery.h"

class t_pimarchivesDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const EmployeeNotInArchiveQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<t_pimarchivesDO> selectWithPage(const EmployeeNotInArchiveQuery::Wrapper& query);
	// ���뵵��
	int update(const t_pimarchivesDO& uObj);
};

#endif // !_T_PIMARCHIVES_DAO_