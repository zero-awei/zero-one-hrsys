#pragma once

#ifndef _ARCHIVES_SERVICE_
#define _ARCHIVES_SERVICE_
#include <list>
#include "domain/vo/archives/ArchivesVO.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/dto/archives/ArchivesDTO.h"

/**
 * ����ʵ��
 */
class ArchivesService_JIUMENG
{
public:
	// ��ѯ��ϸ��Ϣ
	ArchivesPageDTO::Wrapper getAll(const ArchivesQuery::Wrapper& query);
	// ��ҳ��ѯ��������
	ArchivesPageDTO::Wrapper listAll(const ArchivesQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ArchivesDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(const string& id);
};

#endif // !_ARCHIVES_SERVICE_

#pragma once
#ifndef _ARCHIVES_SERVICE_H_
#define _ARCHIVES_SERVICE_H_
#include <list>
#include "domain/vo/archives/ArchivesVO.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/dto/archives/ArchivesDTO.h"

class ArchivesService_JIUMENG
{
public:
	// ��ѯָ����������
	ArchivesPageDTO::Wrapper getAll(const ArchivesQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const ArchivesDTO::Wrapper& dto);
	// �޸�(����)����(����ָ������)
	bool updateDate(const ArchivesDTO::Wrapper& dto);
	// ͨ���������ɾ������
	bool removeData(oatpp::String archivesNo);
};

#endif // !_ARCHIVES_SERVICE_H_
