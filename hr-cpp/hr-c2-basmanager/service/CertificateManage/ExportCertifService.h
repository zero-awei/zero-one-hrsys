#pragma once
#ifndef _EXPORTCERTIF_SERVICE_
#define _EXPORTCERTIF_SERVICE_
#include <list>
#include "domain/vo/CertificateManage/ExportCertifJsonVO.h"
#include "domain/query/CertificateManage/ExportCertifQuery.h"
#include "domain/dto/CertificateManage/ExportCertifDTO.h"

class ExportCertifService
{
public:
	// 分页查询所有数据
	ExportCertifDTO::Wrapper listAll(const ExportCertifQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ExportCertifDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const ExportCertifDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_EXPORTCERTIF_SERVICE_

