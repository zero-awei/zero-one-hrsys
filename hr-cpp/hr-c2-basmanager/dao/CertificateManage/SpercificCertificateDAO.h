#pragma once
/**
 *  证书管理 —— 证书信息 —— 查询、更新指定证书 —— 楚孟献
 */

#ifndef _SPERCIFIC_CERTIFICATE_DAO_
#define _SPERCIFIC_CERTIFICATE_DAO_
#include "BaseDAO.h"
#include "SpercificCertificateMapper.h"
#include "../../domain/do/CertificateManage/SpercificCertificateDO.h"
#include "../../domain/query/CertificateManage/SpercificCertificateQuery.h"

class SpercificCertificateDAO : public BaseDAO
{
public:
	// 查询数据
	std::list<SpercificCertificateDO> querySpercificC(const SpercificCertificateQuery::Wrapper& query);
	// 修改数据
	int update(const SpercificCertificateDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_SpercificCertificate_DAO_
