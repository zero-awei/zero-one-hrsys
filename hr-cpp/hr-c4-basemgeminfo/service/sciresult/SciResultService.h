#pragma once
#ifndef _SCIRESULTSERVICE_H_
#define _SCIRESULTSERVICE_H_
#include <list>
#include "domain/vo/sciresult/SciResultVO.h"
#include "domain/query/sciresult/SciResultQuery.h"
#include "domain/dto/sciresult/AddSciResultDTO.h"
#include "domain/dto/sciresult/DelSciResultDTO.h"
#include "domain/dto/sciresult/Add2SciResultDTO.h"

using namespace oatpp;

class SciResultService
{
public:
	// 分页查询所有数据
	SciResultPageDTO::Wrapper listAll(const SciResultQuery::Wrapper& query);
	uint64_t saveData(const Add2SciResultDTO::Wrapper& dto, const PayloadDTO& payload);
	bool removeData(const DelSciResultDTO::Wrapper& dto);
	uint64_t saveManyData(const String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid, const PayloadDTO& payload);
};

#endif // !_SCIRESULTSERVICE_H_