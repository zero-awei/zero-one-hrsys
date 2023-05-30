#pragma once
#pragma once
#define _CERTIFICATE_MAPPER_
#include "stdafx.h"
#include "Mapper.h"
#include "../../domain/do/Certificate/CertificateDo.h"

/**
 * 
 */
class CertificateMapper : public Mapper<CertificateDO>
{
public:
	CertificateDO mapper(ResultSet* resultSet) const override
	{
		CertificateDO data;
		data.setseialNo(resultSet->getUInt64(11));
		data.setpimQualTypeName(resultSet->getString(200));
		return data;
	}
};
