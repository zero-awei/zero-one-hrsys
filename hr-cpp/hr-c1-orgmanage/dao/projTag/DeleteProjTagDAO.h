#pragma once
#ifndef _DELETEPROJTAGDAO_H_
#define _DELETEPROJTAGDAO_H_
#include "BaseDAO.h"
#include "domain/do/projTag/ProjTagDO.h"
#include "domain/query/projTag/PageProjTagQuery.h"

/**
 * 项目标签 - 删除项目标签DAO
 * 负责人 : 咫尺之书
 */
class DeleteProjTagDAO : public BaseDAO
{
public:
	int deleteById(string id);
};
#endif // !_DELETEPROJTAGDAO_H_