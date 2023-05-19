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
		
		data.setProfessoranalysis_name(resultSet->getString(5));
		data.setCredentials_num(resultSet->getString(6));
		data.setProfessor_grades(resultSet->getString(7));
		data.setMajor(resultSet->getString(8));
		data.setZchqrq(resultSet->getString(9));
		data.setReviewbody(resultSet->getString(10));
		data.setLssuingagency(resultSet->getString(11));
		data.setEmploytime(resultSet->getString(12));
		data.setEnable(resultSet->getString(13));
		
		return data;
	}
};

#endif 
