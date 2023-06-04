#pragma once
#include"../hr-c4-basemgeminfo/domain/do/pimarmycadres/PimarmycadresDO.h"



class PimarmycadresMapper :public  Mapper<PimarmycadresDO> {
public:
	PimarmycadresDO mapper(ResultSet* resultSet) const override {
		PimarmycadresDO data;
		data.setPimid
		(resultSet->getString(1));
		data.setForm
		(resultSet->getString(2));
		data.setLevel
		(resultSet->getString(3));
		data.setOccurtime
		(resultSet->getString(4));
		data.setAnnexPath
		(resultSet->getString(5));
		data.setPimarmycadresid
		(resultSet->getString(6));

		return data;
	}


};

class PimarmycadresPageMapper : public Mapper<PimarmycadresFindDO> {
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

