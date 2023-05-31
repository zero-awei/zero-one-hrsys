#pragma once
#ifndef _CERTIFICATEMAPPER_H_
#define _CERTIFICATEMAPPER_H_

#include "stdafx.h"
#include "Mapper.h"
#include "../../domain/do/Certificate/CertificateDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class CertificateMapper : public Mapper<CertificateDO>
{
public:
	CertificateDO mapper(ResultSet* resultSet) const override
	{
		CertificateDO data;
		data.setseialNo(resultSet->getUInt64("SEIALNO"));
		data.setpimQualTypeName(resultSet->getString("PIMQUALTYPENAME"));
		return data;
	}
};

#endif // _CERTIFICATE_MAPPER_H_
