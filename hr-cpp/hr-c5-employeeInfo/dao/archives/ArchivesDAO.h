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
	// ͳ����������
	uint64_t count(const ArchivesCenterQuery::Wrapper& query);
	// ��ҳ��ѯ������
	list<archivesCenterDO> selectWithPage(const ArchivesCenterQuery::Wrapper& query);
};

class ArchivesDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ArchivesCenterQuery::Wrapper& query);
	// ��ѯָ���������� ��serviceʵ����getAll����
	list<archivesinfoDO> selectAll(const ArchivesQuery::Wrapper& query);
	// ����ָ������
	int update(const archivesinfoDO& uObj);
};

#endifclass ArchivesDAO : public BaseDAO
{
public:
	// ��ѯ��ϸ����
	list<t_pimarchivesDO> selectAll(const ArchivesQuery::Wrapper& query);
	// ͳ����������
	uint64_t count(const ArchivesQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<t_pimarchivesDO> selectWithPage(const ArchivesQuery::Wrapper& query);
	// �������� 
	uint64_t insert(const t_pimarchivesDO& iObj, uint64_t id);
	// ͨ��IDɾ������
	int deleteById(const string& id);
};
#endif // !_ARCHIVES_DAO_
