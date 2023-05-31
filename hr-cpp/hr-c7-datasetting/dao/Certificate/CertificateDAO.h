#pragma once
#ifndef _CERTIFICATE_DAO_
#define _CERTIFICATE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Certificate/CertificateDO.h"
#include "../../domain/query/Certificate/CertificateQuery.h"

/**
 * 示例表数据库操作实现
 */
class CertificateDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CertificateQuery::Wrapper& query);
	// 分页查询数据
	list<CertificateDO> selectWithPage(const CertificateQuery::Wrapper& query);
	// 通过姓名查询数据
	list<CertificateDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const CertificateDO& iObj);
	// 修改数据
	int update(const CertificateDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_CERTIFICATE_DAO_
