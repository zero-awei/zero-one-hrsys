#pragma once

#ifndef _JOBTITLE_DAO_
#define _JOBTITLE_DAO_

#include "BaseDAO.h"
#include "./domain/do/JobTitle/JobTitleDo.h"
#include "./domain/query/JobTitle/JobTitleQuery.h"
#include "./domain/dto/JobTitle/JobTitleDTO.h"

class JobTitleDAO :public BaseDAO {
public:
	// 查询数据条数
	uint64_t count(const JobTitleQuery::Wrapper& query);
	// 查询数据结果
	list<JobTitleDO> selectAll(const JobTitleQuery::Wrapper& query);

	// 添加职称
	uint64_t addTitle(const JobTitleDO& aObj);

	// 批量删除职称
	uint64_t removeById(const JobTitleDeleteDTO::Wrapper& list);
};

#endif