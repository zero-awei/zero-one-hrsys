#pragma once
#ifndef _JOB_TITLE_INFO_DAO_H_
#define _JOB_TITLE_INFO_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/JobTitle/JobTitleDo.h"
#include "../../domain/dto/JobTitleInfo/JobTitleInfoDTO.h"	

class JobTitleInfoDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const JobTitleInfoDTO::Wrapper& query);
	// 导出所有数据（查询所有数据）
	std::list<JobTitleDo> selectAll(const JobTitleInfoDTO::Wrapper& query);
	int update(const JobTitleInfoDTO& uObj);
};

#endif // !_JOB_TITLE_INFO_DAO_H_
