#pragma once
#define _CERTIFICATE_MAPPER_
#include "stdafx.h"
#include "Mapper.h"
#include "../../domain/do/Certificate/CertificateDo.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class CertificateMapper : public Mapper<CertificateDO>
{
public:
	CertificateDO mapper(ResultSet* resultSet) const override
	{
		CertificateDO data;
		data.setseialNo(resultSet->getString(11));
		data.setpimQualTypeName(resultSet->getString(200));
		return data;
	}
};
