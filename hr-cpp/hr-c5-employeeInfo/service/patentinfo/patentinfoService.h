#pragma once

#ifndef PATENTINFO_SERVICE_
#define PATENTINFO_SERVICE_
#include "domain/vo/paptentinfo/PatentinfoVO.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"
#include "domain/dto/patentinfo/DelPatentDTO.h"
#include "domain/dto/patentinfo/AddPatentDTO.h"
//#include "oatpp/core/data/mapping/type/Object.hpp"

/**
 * 论文信息服务实现
 */
class PatentinfoService
{
public:
	// 分页查询所有数据
	PatentinfoPageDTO::Wrapper listAll(const PatentinfoQuery::Wrapper& query);


	// 添加数据
	int saveData(const AddPatentDTO::Wrapper& dto);
	
	// 通过ID删除数据 支持批量删除
	bool removeData(const oatpp::List<oatpp::String>& dto);


	// 查询数据ID
	uint64_t selectPaperID(const PatentinfoDTO::Wrapper& dto);
};

#endif // !_SAMPLE_SERVICE_

