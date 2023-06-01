#pragma once
#ifndef _CERTIFICATE_INFORMATION_MAPPER_H_
#define _CERTIFICATE_INFORMATION_MAPPER_H_
#include "Mapper.h"
#include "../../../domain/do/certificate-information/CertificateInformationDO.h"

class CertificateInformationMapper : public Mapper<CertificateInformationDO>
{
public:
	CertificateInformationDO mapper(ResultSet* resultSet) const override
	{
		CertificateInformationDO data;
		data.setZgzsbh(resultSet->getString(1));
		data.setPimvocationalname(resultSet->getString(2));
		data.setZslx(resultSet->getString(3));
		data.setZghqrq(resultSet->getString(4));
		data.setZgsydw(resultSet->getString(5));
		data.setFzyxq(resultSet->getString(6));
		data.setPimpersonid(resultSet->getString(7));
		return data;
	}
};

#endif 
