#pragma once
#ifndef _CERTIFICATE_INFORMATION_DAO_H_
#define _CERTIFICATE_INFORMATION_DAO_H_
#include "BaseDAO.h"
#include "../../../domain/do/certificate-information/CertificateInformationDO.h"
#include "../../../domain/query/certificate-information/CertificateInformationPageQuery.h"

class CertificateInformationDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CertificateInformationPageQuery::Wrapper& query);
	// 分页查询数据
	list<CertificateInformationDO> selectWithPage(const CertificateInformationPageQuery::Wrapper& query);
};

#endif //
