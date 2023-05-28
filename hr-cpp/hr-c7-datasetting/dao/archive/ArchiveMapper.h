#pragma once
#define _ARCHIVE_MAPPER_
#include "stdafx.h"
#include "Mapper.h"
#include "../../domain/do/archive/ArchiveDo.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ArchiveMapper : public Mapper<ArchiveDO>
{
public:
	ArchiveDO mapper(ResultSet* resultSet) const override
	{
		ArchiveDO data;
		data.setsortID(resultSet->getUInt64(1));
		data.setarchiveName(resultSet->getString(2));
		data.setcabinetNum(resultSet->getInt(3));
		data.setlayerNum(resultSet->getInt(4));
		data.setnumID(resultSet->getInt(4));
		return data;
	}
};
