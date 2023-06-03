#pragma once
#include"../hr-c4-basemgeminfo/domain/do/pimarmycadres/PimarmycadresDO.h"


class PimarmycadresMapper :public  Mapper<PimarmycadresFindDO> {
public:
	PimarmycadresFindDO mapper(ResultSet* resultSet) const override {
		PimarmycadresFindDO data;
		data.setpIMID(resultSet->getString(1));
		data.setfORM(resultSet->getString(2));
		data.setlEVEL(resultSet->getString(3));
		data.setoCCURTIME(resultSet->getString(4));
		data.setaNNEXPATH(resultSet->getString(5));
		//data.setpIMARMYCADRESID(resultSet->getString(6));

		return data;
	}


};