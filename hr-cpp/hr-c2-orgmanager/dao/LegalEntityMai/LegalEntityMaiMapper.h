#pragma once
#ifndef _LEGALENTITYMAIMAPPER_H_
#define _LEGALENTITYMAIMAPPER_H_

#include "Mapper.h"
#include "domain/do/LegalEntityMai/ormsignorgDO.h"

/* 法人主体维护字段匹配映射--（组织管理-数据设置-法人主体维护）--TripleGold */
class LegalEntityMaiMapper : public Mapper<OrmsignorgDO>
{
public:
	OrmsignorgDO mapper(ResultSet* resultSet) const override
	{
		OrmsignorgDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setCode(resultSet->getString(3));

		//data.setORMSIGNORGID(resultSet->getString(1));
		//data.setUPDATEMAN(resultSet->getString(2));
		//data.setCREATEMAN(resultSet->getString(3));
		//data.setCREATEDATE(resultSet->getString(4));
		//data.setORMSIGNORGNAME(resultSet->getString(5));
		//data.setUPDATEDATE(resultSet->getString(6));
		//data.setORGCODE(resultSet->getString(7));
		//data.setZZJC(resultSet->getString(8));
		return data;
	}
};

#endif // !_LEGALENTITYMAIMAPPER_H_