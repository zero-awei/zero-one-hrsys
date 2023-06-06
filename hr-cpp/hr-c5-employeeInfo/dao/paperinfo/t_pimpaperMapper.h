#pragma once
#ifndef _T_PIMPAPER_MAPPER_
#define _T_PIMPAPER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/paperinfo/t_pimpaperDO.h"

/**
 * 论文信息表字段匹配映射
 */
class t_pimpaperMapper : public Mapper<t_pimpaperDO>
{
public:
	t_pimpaperDO mapper(ResultSet* resultSet) const override
	{
		t_pimpaperDO data;
		data.setFbsj(resultSet->getString(1));
		data.setCbs(resultSet->getString(2));
		data.setKwqs(resultSet->getInt(3));
		data.setFj(resultSet->getString(4));
		data.setGrzlwzzzdpm(resultSet->getInt(5));
		data.setKwmc(resultSet->getString(6));
		data.setPimpapername(resultSet->getString(7));
		return data;
	}
};

#endif