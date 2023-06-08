#pragma once
#ifndef _JOBTITLE_MAPPER_
#define _JOBTITLE_MAPPER_

#include "./domain/do/JobTitle/JobTitleDo.h"

class JobTitleMapper :public Mapper<JobTitleDO> {
public:
	JobTitleDO mapper(ResultSet* resultSet) const override
	{
		JobTitleDO data;
		data.setId(resultSet->getString(1));
		//cout << "id:" << data.getId() << endl;
		data.setEmployee_Id(resultSet->getString(2));
		data.setEmployee_Name(resultSet->getString(3));
		data.setEmployee_State(resultSet->getString(4));
		data.setOrg_Name(resultSet->getString(5));
		data.setJobtitle_Name(resultSet->getString(6));
		data.setGet_Time(resultSet->getString(7));
		data.setCertificate_Id(resultSet->getString(8));
		data.setProfessional_Cate(resultSet->getString(9));
		data.setJobtitle_Grades(resultSet->getString(10));
		data.setEmployment_Month(resultSet->getString(11));
		data.setTitle_Employment_Time(resultSet->getString(12));
		data.setIssuing_Authority(resultSet->getString(13));
		data.setJudging_Unit(resultSet->getString(14));
		data.setB_Highest_Professional_Title(resultSet->getString(15));
		return data;
	}
};

class JobTitlePpidMapper :public Mapper<JobTitleAddDO> {
public:
	JobTitleAddDO mapper(ResultSet* resultSet) const override
	{
		JobTitleAddDO data;
		data.setPimperson_Id(resultSet->getString(1));
		return data;
	}
};


#endif // !_JOBTITLE_MAPPER_
