#pragma once
#ifndef _PATENTINFO_MAPPER_
#define _PATENTINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/patentinfo/t_pimpatentDO.h"

/**
 * 专利信息表字段匹配映射
 */
class PatentinfoMapper : public Mapper<PatentinfoDO>
{
public:
	PatentinfoDO mapper(ResultSet* resultSet) const override
	{
		PatentinfoDO data;
		data.setZLH(resultSet->getString(1));
		data.setUPDATEDATE(resultSet->getString(2));
		data.setPIMPATENTID(resultSet->getString(3));
		data.setZLHQSJ(resultSet->getString(4));
		data.setPIMPATENTNAME(resultSet->getString(5));
		data.setUPDATEMAN(resultSet->getString(6));
		data.setCREATEMAN(resultSet->getString(7));
		data.setCREATEDATE(resultSet->getString(8));
		data.setZLPZGB(resultSet->getString(9));
		data.setPIMPERSONID(resultSet->getString(10));
		data.setJLSS(resultSet->getString(11));
		data.setJLSPZT(resultSet->getString(12));
		data.setJLGLBH(resultSet->getString(13));
		data.setJLCZZ(resultSet->getString(14));
		data.setENCLOLURE(resultSet->getString(15));
		data.setREASON(resultSet->getString(16));


		return data;
	}
};

#endif // !_PATENTINFO_MAPPER_
