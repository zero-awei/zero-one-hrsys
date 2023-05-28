#pragma once
#ifndef _JOBTITLE_INFO_MAPPER_H_
#define _JOBTITLE_INFO_MAPPER_H_
#include "Mapper.h"
#include "domain/do/JobTitle/JobTitleDo.h"

class JobTitleInfoMapper :public Mapper<JobTitleDo>
{
public:
	JobTitleDo mapper(ResultSet* resultSet) const override
	{
		JobTitleDo data;
		data.setId(resultSet->getInt64(0));
		data.setName(resultSet->getString(1));
		data.setCertId(resultSet->getInt64(2));
		data.setGrades(resultSet->getString(3));
		data.setJobType(resultSet->getString(4));
		data.setCategory(resultSet->getString(5));
		data.setGetDate(resultSet->getString(6));
		return data;
	}
};

#endif // !_JOBTITLE_INFO_MAPPER_H_
