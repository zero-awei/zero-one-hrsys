#pragma once
#ifndef _SCIENTIFICSERVICE_H_
#define _SCIENTIFICSERVICE_H_
#include "domain/vo/scientific/ScientificVO.h"
#include "domain/query/scientific/ScientificQuery.h"
#include "domain/dto/scientific/ScientificDTO.h"

class ScientificService
{
public:
	//查询详情
	ScientificDTO::Wrapper listDetail(const ScientificViewQuery::Wrapper& query);
	// 修改数据
	bool updateData(const ScientificDTO::Wrapper& dto);
	//导出
	string download(const ScientificDownloadQuery::Wrapper& query);
};

#endif // !_SCIENTIFICSERVICE_H_

