#pragma once
/*
证书管理-新建证书--pine
*/
#ifndef _CREATE_NEW_CER_DAO_
#define _CREATE_NEW_CER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CertificateManage/CertificateDO.h"
#include "../../domain/query/CertificateManage/CreateNewCerQuery.h"

/**
 * （员工编号、证书名称）(员工姓名要跨表)
 */
class CreateNewCerDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const CertificateDO& iObj);
};
#endif // !_CREATE_NEW_CER_DAO_
