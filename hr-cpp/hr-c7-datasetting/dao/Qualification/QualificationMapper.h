#pragma once
#define _QUALIFICATION_MAPPER_
#include "stdafx.h"
#include "Mapper.h"
#include "../../domain/do/Qualification/QualificationDo.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class QualificationMapper : public Mapper<QualificationDO>
{
public:
	QualificationDO mapper(ResultSet* resultSet) const override
	{
		QualificationDO data;
		data.setquaLevel(resultSet->getString(100));
		data.setpimQualMajorName(resultSet->getString(200));
		data.setquaMajor(resultSet->getString(100));
		return data;
	}
};
