#pragma once

#ifndef _TRAININGRECORDMAPPER_H_
#define _TRAININGRECORDMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/trainingrecord/TrainingRecordDO.h"

class TrainingRecordMapper : public Mapper<TrainingRecordDO>
{
public:
	TrainingRecordDO mapper(ResultSet* resultSet) const override
	{
		TrainingRecordDO data;

		data.set_TRMTRIANPERSONID(resultSet->getString(1));
		data.set_PXBJ(resultSet->getString(2));
		data.set_TRAINBEGIN(resultSet->getString(3));
		data.set_TRAINEND(resultSet->getString(4));
		data.set_PXKC(resultSet->getString(5));
		data.set_TRMTRAINAGENCYNAME(resultSet->getString(6));
		data.set_TRAINRES(resultSet->getString(7));
		data.set_FS(resultSet->getString(8));

		return data;

	}
};

#endif