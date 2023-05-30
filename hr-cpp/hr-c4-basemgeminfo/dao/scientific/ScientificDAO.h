#pragma once
#ifndef _SCIENTIFICDAO_H_
#define _SCIENTIFICDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/scientific/ScientificDO.h"
#include "../../domain/query/scientific/ScientificQuery.h"

class ScientificDAO : public BaseDAO
{
public:
	// 查询详情数据
	list<ScientificDO> selectDetail(const ScientificViewQuery::Wrapper& query);
	// 修改数据
	int update(const ScientificDO& uObj);
	// 分页查询数据
	list<ScientificDO> selectWithPage(const ScientificDownloadQuery::Wrapper& query);

};

#endif // !_ScientificDAO_H_
