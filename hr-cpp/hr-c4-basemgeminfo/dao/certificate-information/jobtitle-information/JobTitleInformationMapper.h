#pragma once
#ifndef _JOBTITLEINFORMATION_MAPPER_H_
#define _JOBTITLEINFORMATION_MAPPER_H_
#include "Mapper.h"
#include "../../../domain/do/certificate-information/JobTitleInformationDO.h"

class JobTitleInformationMapper : public Mapper<JobTitleInformationDO>
{
public:
	JobTitleInformationDO mapper(ResultSet* resultSet) const override
	{
		JobTitleInformationDO data;
		data.setProfessoranalysis_name(resultSet->getString(1));
		data.setCredentials_num(resultSet->getString(2));
		data.setProfessor_grades(resultSet->getString(3));
		data.setMajor(resultSet->getString(4));
		data.setZchqrq(resultSet->getString(5));
		data.setReviewbody(resultSet->getString(6));
		data.setLssuingagency(resultSet->getString(7));
		data.setEmploytime(resultSet->getString(8));
		data.setEnable(resultSet->getString(9));
		data.setEmployeeid(resultSet->getString(10));
		return data;
	}
};

#endif 
