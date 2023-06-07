#pragma once
#ifndef _ARCHIVES_CENTER_SERVICE_
#define _ARCHIVES_CENTER_SERVICE_
#include <list>
#include "domain/vo/archivesCenter/ArchivesCenterVO.h"
#include "domain/query/archivesCenter/ArchivesCenterQuery.h"
#include "domain/dto/archivesCenter/ArchivesCenterDTO.h"
/**
 * ��ҳ��ѯ������
 */
class ArchivesCenterService
{
public:
	// ��ҳ��ѯ������
	ArchivesCenterDTO::Wrapper listAll(const ArchivesCenterQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_#pragma once
