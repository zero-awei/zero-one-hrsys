#pragma once
#ifndef _T_PIMARCHIVES_MAPPER_
#define _T_PIMARCHIVES_MAPPER_

#include "Mapper.h"
#include "../../domain/do/t_pimarchives/t_pimarchivesDO.h"

class t_pimarchivesMapper : public Mapper<t_pimarchivesDO>
{
public:
	t_pimarchivesDO mapper(ResultSet* resultSet) const override
	{
		t_pimarchivesDO data;
		data.setDabh(resultSet->getString(1));
		data.setOrgname(resultSet->getString(2));
		data.setDabgd(resultSet->getString(3));
		data.setArchivescentername(resultSet->getString(4));
		data.setDastate(resultSet->getString(5));
		data.setYgbh(resultSet->getString(6));
		data.setPimpersonname(resultSet->getString(7));
		data.setOrmorgname(resultSet->getString(8));
		data.setYgzt(resultSet->getString(9));
		data.setOperations(resultSet->getString(10));
		return data;
	}
};

#endif // !_T_PIMARCHIVES_MAPPER_