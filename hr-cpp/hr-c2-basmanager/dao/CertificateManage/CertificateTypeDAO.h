#pragma once
#ifndef _CERTIFICATETYPE_DAO_
#define _CERTIFICATETYPE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CertificateManage/CertificateTypeDO.h"
#include "../../domain/query/CertificateManage/CertificateTypeQuery.h"

/**
 * 证书类型分页查询对象--(证书管理-查询证书类型列表)--weixiaoman
 */
class CertificateTypeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CertificateTypeQuery::Wrapper& query);
	// 分页查询数据
	list<CertificateTypeDO> selectWithPage(const CertificateTypeQuery::Wrapper& query);
};
#endif // !_CERTIFICATETYPE_DAO_