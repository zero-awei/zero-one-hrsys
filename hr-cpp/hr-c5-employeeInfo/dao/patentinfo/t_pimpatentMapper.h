#pragma once
#ifndef _T_PIMPAPER_MAPPER_
#define _T_PIMPAPER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/paperinfo/t_pimpaperDO.h"

/**
 * 论文信息表字段匹配映射
 */
class t_pimpatentMapper : public Mapper<PatentinfoDO>
{
public:
	PatentinfoDO mapper(ResultSet* resultSet) const override
	{
		PatentinfoDO data;
		data.setZLH(resultSet->getString(1));
		data.setPIMPATENTNAME(resultSet->getString(2));
		data.setZLHQSJ(resultSet->getString(3));
		data.setZLHQSJ(resultSet->getString(4));
		data.setPIMPATENTNAME(resultSet->getString(5));
		data.setENCLOLURE(resultSet->getString(6));
		return data;
	}
};

#endif