#pragma once
/*
证书管理-分页查询证书列表--pine
*/
#ifndef _CHECH_CER_LIST_DAO_
#define _CHECH_CER_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CertificateManage/CertificateDO.h"
#include "../../domain/query/CertificateManage/CheckCerListQuery.h"

/**
 * 示例表数据库操作实现（员工编号、员工姓名、证书名称）
 */
class CheckCerListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CheckCerListQuery::Wrapper& query);
	// 分页查询数据
	list<CertificateDO> selectWithPage(const CheckCerListQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_
