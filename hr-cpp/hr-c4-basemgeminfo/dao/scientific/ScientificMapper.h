#pragma once
#ifndef _SCIENTIFICMAPPER_H_
#define _SCIENTIFICMAPPER_H_
#include "Mapper.h"
#include "../../domain/do/scientific/ScientificDO.h"

class ScientificMapper : public Mapper<ScientificDO>
{
public:
	ScientificDO mapper(ResultSet* resultSet) const override
	{
		ScientificDO data;
		data.setUpdateman(resultSet->getString(1));
		data.setPimresearchfindingsname(resultSet->getString(2));
		data.setFj(resultSet->getString(3));
		data.setEnable(resultSet->getString(4));
		data.setCreatedate(resultSet->getString(5));
		data.setUpdatedate(resultSet->getString(6));
		data.setCreateman(resultSet->getString(7));
		data.setPimresearchfindingsid(resultSet->getString(8));
		data.setPimpersonid(resultSet->getString(9));
		data.setHqsj(resultSet->getString(10));
		data.setJlss(resultSet->getString(11));
		data.setJlglbh(resultSet->getString(12));
		data.setJlczz(resultSet->getString(13));
		data.setReason(resultSet->getString(14));
		return data;
	}
};

#endif // !_SCIENTIFICMAPPER_H_
