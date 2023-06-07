#pragma once

#ifndef _ARCHIVES_SERVICE_
#define _ARCHIVES_SERVICE_
#include <list>
#include "domain/vo/archives/ArchivesVO.h"
#include "domain/query/archives/ArchivesQuery.h"
#include "domain/dto/archives/ArchivesDTO.h"

/**
 * 服务实现
 */
class ArchivesService_JIUMENG
{
public:
	// 查询详细信息
	ArchivesPageDTO::Wrapper getAll(const ArchivesQuery::Wrapper& query);
	// 分页查询所有数据
	ArchivesPageDTO::Wrapper listAll(const ArchivesQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ArchivesDTO::Wrapper& dto);
	// 通过ID删除数据
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
	// 查询指定档案详情
	ArchivesPageDTO::Wrapper getAll(const ArchivesQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ArchivesDTO::Wrapper& dto);
	// 修改(更新)数据(更新指定档案)
	bool updateDate(const ArchivesDTO::Wrapper& dto);
	// 通过档案编号删除数据
	bool removeData(oatpp::String archivesNo);
};

#endif // !_ARCHIVES_SERVICE_H_
