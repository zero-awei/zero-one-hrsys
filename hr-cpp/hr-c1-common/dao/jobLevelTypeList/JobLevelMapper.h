#pragma once
#ifndef _JOBLEVELMAPPER_H_
#define _JOBLEVELMAPPER_H_

#include "Mapper.h"
#include "domain/do/jobLevelTypeList/JobLevelTypeDO.h"

/**
 * 职称等级类型下拉列表数据库字段匹配映射
 * 负责人：咫尺之书
 */
class JobLevelMapper : public Mapper<JobLevelTypeDO>
{
public:
	JobLevelTypeDO mapper(ResultSet* result) const override
	{
		JobLevelTypeDO data;
		data.setCode(result->getString(1));
		data.setJobLevel(result->getString(2));
		return data;
	}
};

#endif // !_JOBLEVELMAPPER_H_