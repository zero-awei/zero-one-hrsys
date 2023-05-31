#pragma once
#ifndef _CERTIFICATETYPE_MAPPER_
#define _CERTIFICATETYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CertificateManage/CertificateTypeDO.h"

/**
 * 证书类型分页查询Mapper--(证书管理-查询证书类型信息)--weixiaoman
 */
class CertificateTypeMapper : public Mapper<CertificateTypeDO>
{
public:
	CertificateTypeDO mapper(ResultSet* resultSet) const override
	{
		CertificateTypeDO data;
		data.setCerType(resultSet->getString(1));
		data.setId(resultSet->getString(2));
		return data;
	}
};

#endif // !_CERTIFICATETYPE_MAPPER_