#pragma once
#ifndef _JOBTITLE_INFO_MAPPER_H_
#define _JOBTITLE_INFO_MAPPER_H_
#include "Mapper.h"
#include "domain/do/JobTitle/JobTitleDo.h"

class JobTitleInfoMapper :public Mapper<JobTitleDO>
{
public:
	JobTitleDO mapper(ResultSet* resultSet) const override
	{
		JobTitleDO data;
		data.setId(resultSet->getString(0));
		data.setEmployee_Name(resultSet->getString(1));
		data.setCertificate_Id(resultSet->getString(2));
		data.setJobtitle_Grades(resultSet->getString(3));
		// data.setJobType(resultSet->getString(4));
		data.setProfessional_Cate(resultSet->getString(5));
		// data.setGetDate(resultSet->getString(6));
		return data;
	}
};

#endif // !_JOBTITLE_INFO_MAPPER_H_
