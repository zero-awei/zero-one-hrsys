#pragma once
#ifndef _CERTIFICATE_SERVICE_
#define _CERTIFICATE_SERVICE_
#include <list>
#include "domain/vo/Certificate/CertificateVO.h"
#include "domain/query/Certificate/CertificateQuery.h"
#include "domain/dto/Certificate/CertificateDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class CertificateService
{
public:
	// 分页查询所有数据
	CertificatePageDTO::Wrapper listAll(const CertificateQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const CertificateDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const CertificateDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_CERTIFICATE_SERVICE_

