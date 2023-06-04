#pragma once
#ifndef _DELETECERTIF_SERVICE_
#define _DELETECERTIF_SERVICE_
#include <list>

#include "../../domain/dto/CertificateManage/RemoveCertifDTO.h"

class DeleteCertifService
{
public:
	// 通过ID删除数据
	bool removeData(const RemoveCertifDTO::Wrapper& dto);
};

#endif // !_DELETECERTIF_SERVICE_

