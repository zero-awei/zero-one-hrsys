#pragma once
#ifndef _J_PATENTINFO_MAPPER_
#define _J_PATENTINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/J_patentinfo/J_t_pimpatentDO.h"

/**
 * 专利信息表字段匹配映射
 */
class PatentinfoMapper : public Mapper<J_PatentinfoDO>
{
public:
	J_PatentinfoDO mapper(ResultSet* resultSet) const override
	{
		J_PatentinfoDO data;
		//data.setZLH(resultSet->getString(1));
		//data.setUPDATEDATE(resultSet->getString(2));
		//data.setPIMPATENTID(resultSet->getString(3));
		//data.setZLHQSJ(resultSet->getString(4));
		//data.setPIMPATENTNAME(resultSet->getString(5));
		//data.setUPDATEMAN(resultSet->getString(6));
		//data.setCREATEMAN(resultSet->getString(7));
		//data.setCREATEDATE(resultSet->getString(8));
		//data.setZLPZGB(resultSet->getString(9));
		//data.setPIMPERSONID(resultSet->getString(10));
		//data.setJLSS(resultSet->getString(11));
		//data.setJLSPZT(resultSet->getString(12));
		//data.setJLGLBH(resultSet->getString(13));
		//data.setJLCZZ(resultSet->getString(14));
		//data.setENCLOLURE(resultSet->getString(15));
		//data.setREASON(resultSet->getString(16));
		data.setCREATEDATE(resultSet->getString(1));
		data.setCREATEMAN(resultSet->getString(2));
		data.setENABLE(resultSet->getString(3));
		data.setENCLOLURE(resultSet->getString(4));
		data.setJLCZZ(resultSet->getString(5));
		data.setJLGLBH(resultSet->getString(6));
		data.setJLSPZT(resultSet->getString(7));
		data.setJLSS(resultSet->getString(8));
		data.setORGID(resultSet->getString(9));
		data.setORGSECTORID(resultSet->getString(10));
		data.setORMORGID(resultSet->getString(11));
		data.setORMORGSECTORID(resultSet->getString(12));
		data.setPIMPATENTID(resultSet->getString(13));
		data.setPIMPATENTNAME(resultSet->getString(14));
		data.setPIMPERSONID(resultSet->getString(15));
		data.setPIMPERSONNAME(resultSet->getString(16));
		data.setREASON(resultSet->getString(17));
		data.setUPDATEDATE(resultSet->getString(18));
		data.setUPDATEMAN(resultSet->getString(19));
		data.setYGBH(resultSet->getString(20));
		data.setZLH(resultSet->getString(21));
		data.setZLHQSJ(resultSet->getString(22));
		data.setZLPZGB(resultSet->getString(23));
		return data;
	}
};

#endif // !_PATENTINFO_MAPPER_
