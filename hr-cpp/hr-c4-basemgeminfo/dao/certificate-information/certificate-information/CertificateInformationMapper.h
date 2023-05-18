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
		/*data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setOrmorgname(resultSet->getString(3));
		data.setState(resultSet->getString(4));*/
		data.setZgzsbh(resultSet->getString(5));
		data.setPimvocationalname(resultSet->getString(6));
		data.setZslx(resultSet->getString(7));
		data.setZghqrq(resultSet->getString(8));
		data.setZgsydw(resultSet->getString(9));
		data.setFzyxq(resultSet->getString(10));
		
		return data;
	}
};

#endif 
