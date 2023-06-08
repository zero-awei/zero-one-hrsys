#include "stdafx.h"
#include "DeleteCertifService.h"
#include "../../dao/CertificateManage/DeleteCertifDAO.h"

bool DeleteCertifService::removeData(const RemoveCertifDTO::Wrapper& dto)
{
	DeleteCertifDAO dao;
	for (auto it=dto->idByBatch->begin(); it!=dto->idByBatch->end(); ++it)
	{
		dao.deleteById(*it);
	}
	return true;
}
