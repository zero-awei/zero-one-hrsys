#pragma once
#ifndef _J_PAPERINFO_MAPPER_
#define _J_PAPERINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/J_paperinfo/J_paperinfoDO.h"

/**
 * 论文信息表字段匹配映射
 */
class PaperinfoMapper : public Mapper<J_PaperinfoDO>
{
public:
	J_PaperinfoDO mapper(ResultSet* resultSet) const override
	{
		J_PaperinfoDO data;

		data.setCBS(resultSet->getString(1));
		data.setCBSHKWMC(resultSet->getString(2));
		data.setCREATEDATE(resultSet->getString(3));
		data.setCREATEMAN(resultSet->getString(4));
		data.setENABLE(resultSet->getString(5));
		data.setFBSJ(resultSet->getString(6));
		data.setFJ(resultSet->getString(7));
		data.setGRZLWZZZDPM(resultSet->getString(8));
		data.setJLCZZ(resultSet->getString(9));
		data.setJLGLBH(resultSet->getString(10));
		data.setJLSPZT(resultSet->getString(11));
		data.setJLSS(resultSet->getString(12));
		data.setKWMC(resultSet->getString(13));
		data.setKWQS(resultSet->getString(14));
		data.setORGID(resultSet->getString(15));
		data.setORGSECTORID(resultSet->getString(16));
		data.setORMORGID(resultSet->getString(17));
		data.setORMORGSECTORID(resultSet->getString(18));
		data.setPIMPAPERID(resultSet->getString(19));
		data.setPIMPAPERNAME(resultSet->getString(20));
		data.setPIMPERSONID(resultSet->getString(21));
		data.setPIMPERSONNAME(resultSet->getString(22));
		data.setREASON(resultSet->getString(23));
		data.setUPDATEDATE(resultSet->getString(24));
		data.setUPDATEMAN(resultSet->getString(25));
		data.setYGBH(resultSet->getString(26));

		return data;
	}
};

#endif // !_PAPERINFO_MAPPER_
