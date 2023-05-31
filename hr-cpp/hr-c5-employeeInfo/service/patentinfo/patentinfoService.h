#pragma once

#ifndef _T_PIMPATENT_SERVICE_
#define _T_PIMPATENT_SERVICE_
#include <list>
#include "domain/vo/patentinfo/PatentinfoVO.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
#include "domain/dto/patentinfo/DelPatentDTO.h"

/**
 * 论文信息服务实现
 */
class patentinfoService
{
public:
	// 分页查询所有数据
	PatentinfoPageDTO::Wrapper listAll(const PatentinfoQuery::Wrapper& query);


	// 保存数据
	uint64_t saveData(const PatentinfoDTO::Wrapper& dto);
	
	// 通过ID删除数据 支持批量删除
	//bool removeData(string id);
	bool removeData(const DelPatentDTO::Wrapper& dto);


	// 查询数据ID
	uint64_t selectPaperID(const PatentinfoDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

