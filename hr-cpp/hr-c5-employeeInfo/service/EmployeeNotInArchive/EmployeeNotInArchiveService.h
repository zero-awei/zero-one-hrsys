#pragma once
#ifndef _ARCHIVES_SERVICE_H_
#define _ARCHIVES_SERVICE_H_
#include <list>
#include "domain/vo/EmployeeNotInArchive/EmployeeNotInArchiveVo.h"
#include "domain/query/EmployeeNotInArchive/EmployeeNotInArchiveQuery.h"
#include "domain/dto/EmployeeNotInArchive/EmployeeNotInArchiveDto.h"

class ArchivesService
{
public:
	// 分页查询数据列表
	EmployeeNotInArchivePageDTO::Wrapper listAll(const EmployeeNotInArchiveQuery::Wrapper& query);
	// 修改数据 调入档案
	bool updateArchive(const EmployeeNotInArchiveDto::Wrapper& dto);
};

#endif // !_ARCHIVES_SERVICE_H_
