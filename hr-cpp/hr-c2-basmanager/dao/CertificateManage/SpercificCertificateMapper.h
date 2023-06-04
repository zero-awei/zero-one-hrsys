#pragma once
/**
 *  证书管理 —— 证书信息 —— 查询、更新指定证书 —— 楚孟献
 */

#ifndef _SPERCIFIC_CERTIFICATE_MAPPER_
#define _SPERCIFIC_CERTIFICATE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CertificateManage/SpercificCertificateDO.h"

/**
 * 离职人员表字段匹配映射
 */
class SpercificCertificateMapper :public Mapper<SpercificCertificateDO>
{
public:
	SpercificCertificateDO mapper(ResultSet* resultSet) const override
	{
		SpercificCertificateDO data;
			data.setPimperSonName	(resultSet->getString(1));
			data.setZgzsbh			(resultSet->getString(2));
			data.setZgzsbh			(resultSet->getString(3));
			data.setPimVocationalName(resultSet->getString(4));
			data.setZgsydw			(resultSet->getString(5));
			data.setregisNumber		(resultSet->getString(6));
			data.setZcdw			(resultSet->getString(7));
			data.setSOCSECPAYUNIT	(resultSet->getString(8));
			data.setBcardNumber		(resultSet->getString(9));
			data.setZghqrq			(resultSet->getString(10));
			data.setCSZCSJ			(resultSet->getString(11));
			data.setXZCSJ			(resultSet->getString(12));
			data.setSxrq			(resultSet->getString(13));
			data.setNSQK			(resultSet->getString(14));
			data.setSYQK			(resultSet->getString(15));
			data.setALTERATION		(resultSet->getString(16));
		return data;
	}
};

#endif