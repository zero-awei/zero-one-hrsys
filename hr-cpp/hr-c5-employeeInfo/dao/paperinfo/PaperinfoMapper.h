#pragma once
#ifndef _PAPERINFO_MAPPER_
#define _PAPERINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/patentinfo/t_pimpatentDO.h"

/**
 * 论文信息表字段匹配映射
 */
class PaperinfoMapper : public Mapper<t_pimpaperDO>
{
public:
	t_pimpaperDO mapper(ResultSet* resultSet) const override
	{
		t_pimpaperDO data;

		data.setGRZLWZZZDPM(resultSet->getString(1));
		data.setUPDATEMAN(resultSet->getString(1));
		data.setPIMPAPERID(resultSet->getString(1));
		data.setCREATEDATE(resultSet->getString(1));
		data.setUPDATEDATE(resultSet->getString(1));
		data.setCREATEMAN(resultSet->getString(1));
		data.setFBSJ(resultSet->getString(1));
		data.setPIMPAPERNAME(resultSet->getString(1));
		data.setCBSHKWMC(resultSet->getString(1));
		data.setPIMPERSONID(resultSet->getString(1));
		data.setFJ(resultSet->getString(1));
		data.setJLSPZT(resultSet->getString(1));
		data.setJLGLBH(resultSet->getString(1));
		data.setJLCZZ(resultSet->getString(1));
		data.setJLSS(resultSet->getString(1));
		data.setCBS(resultSet->getString(1));
		data.setKWMC(resultSet->getString(1));
		data.setKWQS(resultSet->getString(1));
		data.setREASON(resultSet->getString(1));


		return data;
	}
};

#endif // !_PAPERINFO_MAPPER_
