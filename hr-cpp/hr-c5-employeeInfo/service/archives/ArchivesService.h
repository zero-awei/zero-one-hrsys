#pragma once
#ifndef _ARCHIVES_SERVICE_H_
#define _ARCHIVES_SERVICE_H_
#include <list>
#include "domain/vo/archives/ArchivesVO.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/dto/archives/ArchivesDTO.h"

class ArchivesService
{
public:
	// 分页查询所有数据
	// 保存数据
	uint64_t saveData(const ArchivesDTO::Wrapper& dto);
	// 修改数据
	bool updateDate(const ArchivesDTO::Wrapper& dto);
	// 通过档案编号删除数据
	bool removeData(oatpp::String archivesNo);
};

#endif // !_ARCHIVES_SERVICE_H_
