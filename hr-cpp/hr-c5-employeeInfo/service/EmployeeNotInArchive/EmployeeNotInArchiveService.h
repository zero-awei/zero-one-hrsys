#pragma once
#ifndef _ARCHIVES_SERVICE_JIUMENG_H_
#define _ARCHIVES_SERVICE_JIUMENG_H_
#include <list>
#include "domain/vo/EmployeeNotInArchive/EmployeeNotInArchiveVo.h"
#include "domain/query/EmployeeNotInArchive/EmployeeNotInArchiveQuery.h"
#include "domain/dto/EmployeeNotInArchive/EmployeeNotInArchiveDto.h"

class ArchivesService_JIUMENG
{
public:
	// ��ҳ��ѯ�����б�
	EmployeeNotInArchivePageDTO::Wrapper listAll(const EmployeeNotInArchiveQuery::Wrapper& query);
	// �޸����� ���뵵��
	bool updateArchive(const EmployeeNotInArchiveDto::Wrapper& dto);
};

#endif // !_ARCHIVES_SERVICE_H_
