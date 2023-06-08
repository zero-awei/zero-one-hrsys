#pragma once
#ifndef _ARCHIVESSERVICE_H_
#define _ARCHIVESSERVICE_H_
#include <list>
#include "domain/vo/archives/ArchivesVO.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/dto/archives/ArchivesDTO.h"

class ArchivesService {
public:
	// 分页查询所有数据
	ArchivesPageDTO::Wrapper listAll(const ArchivesQuery::Wrapper& query);
};

#endif //!_ARCHIVESSERVICE_H_