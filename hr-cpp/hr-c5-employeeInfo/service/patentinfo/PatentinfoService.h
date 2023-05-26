#pragma once

#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/patentinfo/PatentinfoVO.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/dto/patentinfo/PatentinfoDTO.h"



/**
 * 专利服务实现
 */
class PatentinfoService
{
public:
	// 查询所有数据
	PatentinfoDTO::Wrapper listAll(const PatentinfoQuery::Wrapper& query);

	// 修改数据
	//bool updateData(const PatentinfoDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_
