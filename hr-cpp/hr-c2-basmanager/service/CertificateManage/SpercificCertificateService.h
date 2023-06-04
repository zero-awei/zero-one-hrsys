#pragma once
/**
 *  证书管理 —— 证书信息 —— 查询、更新指定证书 —— 楚孟献
 */
#ifndef _SpercificCertificate_SERVICE_
#define _SpercificCertificate_SERVICE_
#include <list>
#include "domain/vo/CertificateManage/SpercificCertificateVO.h"
#include "domain/query/CertificateManage/SpercificCertificateQuery.h"
#include "domain/dto/CertificateManage/SpercificCertificateDTO.h"
class SpercificCertificateService {
public:
	bool updateData(const SpercificCertificateDTO::Wrapper& dto);
	SpercificCertificateDTO::Wrapper querySpercificCertificate(const SpercificCertificateQuery::Wrapper &query);
};

#endif // !_SpercificCertificate_SERVICE_
#pragma once
