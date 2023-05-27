#pragma once
#ifndef _SCIRESULTSERVICE_H_
#define _SCIRESULTSERVICE_H_
#include <list>
#include "domain/vo/SciResult/SciResultVO.h"
#include "domain/query/SciResult/SciResultQuery.h"
#include "domain/dto/SciResult/AddSciResultDTO.h"
#include "domain/dto/SciResult/DelSciResultDTO.h"
#include "domain/dto/SciResult/Add2SciResultDTO.h"

using namespace oatpp;

class SciResultService
{
public:
	// 分页查询所有数据
	SciResultPageDTO::Wrapper listAll(const SciResultQuery::Wrapper& query);
	uint64_t saveData(const Add2SciResultDTO::Wrapper& dto); 
	bool removeData(const DelSciResultDTO::Wrapper& dto);
	uint64_t saveManyData(const String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid);
};

#endif // !_SCIRESULTSERVICE_H_