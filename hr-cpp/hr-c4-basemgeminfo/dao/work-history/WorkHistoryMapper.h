#pragma once
#ifndef _WORKHISTORY_MAPPER_H_
#define _WORKHISTORY_MAPPER_H_
#include "Mapper.h"
#include "../../domain/do/work-history/WorkHistoryDO.h"

class WorkHistoryMapper : public Mapper<WorkHistoryDO>
{
public:
	WorkHistoryDO mapper(ResultSet* resultSet) const override
	{
		WorkHistoryDO data;
		data.setRzkssj(resultSet->getString(1));
		data.setRzjssj(resultSet->getString(2));
		data.setOrmorgname(resultSet->getString(3));
		data.setOrmdutyname(resultSet->getString(4));
		data.setOrmpostname(resultSet->getString(5));
		data.setCfplx(resultSet->getString(6));
		data.setEnable(resultSet->getString(7));
		
		return data;
	}
};

#endif 
