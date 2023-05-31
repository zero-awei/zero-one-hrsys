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
		data.setUPDATEMAN(resultSet->getString(2));
		data.setPIMPAPERID(resultSet->getString(3));
		data.setCREATEDATE(resultSet->getString(4));
		data.setUPDATEDATE(resultSet->getString(5));
		data.setCREATEMAN(resultSet->getString(6));
		data.setFBSJ(resultSet->getString(7));
		data.setPIMPAPERNAME(resultSet->getString(8));
		data.setCBSHKWMC(resultSet->getString(9));
		data.setPIMPERSONID(resultSet->getString(10));
		data.setFJ(resultSet->getString(11));
		data.setJLSPZT(resultSet->getString(12));
		data.setJLGLBH(resultSet->getString(13));
		data.setJLCZZ(resultSet->getString(14));
		data.setJLSS(resultSet->getString(15));
		data.setCBS(resultSet->getString(16));
		data.setKWMC(resultSet->getString(17));
		data.setKWQS(resultSet->getString(18));
		data.setREASON(resultSet->getString(19));


		return data;
	}
};

#endif // !_PAPERINFO_MAPPER_
