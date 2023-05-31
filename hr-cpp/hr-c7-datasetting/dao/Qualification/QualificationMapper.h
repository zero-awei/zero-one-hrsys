#pragma once
#ifndef _QUALIFICATIONMAPPER_H_
#define _QUALIFICATIONMAPPER_H_

#include "stdafx.h"
#include "Mapper.h"
#include "../../domain/do/Qualification/QualificationDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class QualificationMapper : public Mapper<QualificationDO>
{
public:
	QualificationDO mapper(ResultSet* resultSet) const override
	{
		QualificationDO data;
		data.setpimQualMajorId(resultSet->getString("PIMQUALMAJORID"));
		data.setquaLevel(resultSet->getString("QUALEVEL"));
		data.setpimQualMajorName(resultSet->getString("PIMQUALMAJORNAME"));
		data.setquaMajor(resultSet->getString("QUAMAJOR"));
		return data;
	}
};

#endif // _QUALIFICATIONMAPPER_MAPPER_H_
