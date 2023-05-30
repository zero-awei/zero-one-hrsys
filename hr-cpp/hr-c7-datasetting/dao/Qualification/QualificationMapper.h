#pragma once
#define _QUALIFICATION_MAPPER_
#include "stdafx.h"
#include "Mapper.h"
#include "../../domain/do/Qualification/QualificationDo.h"

/**
 * 
 */
class QualificationMapper : public Mapper<QualificationDO>
{
public:
	QualificationDO mapper(ResultSet* resultSet) const override
	{
		QualificationDO data;
		data.setpimQualMajorId(resultSet->getString(100));
		data.setquaLevel(resultSet->getString(100));
		data.setpimQualMajorName(resultSet->getString(200));
		data.setquaMajor(resultSet->getString(100));
		return data;
	}
};
