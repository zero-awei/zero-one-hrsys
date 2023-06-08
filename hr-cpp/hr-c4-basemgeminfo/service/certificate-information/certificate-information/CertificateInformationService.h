#pragma once
#ifndef _CERTIFICATE_INFORMATION_SERVICE_H_
#define _CERTIFICATE_INFORMATION_SERVICE_H_
#include <list>
#include "domain/vo/certificate-information/CertificateInformationVO.h"
#include "domain/query/certificate-information/CertificateInformationPageQuery.h"
#include "domain/dto/certificate-information/CertificateInformationDTO.h"

class CertificateInformationService
{
public:
	//分页查询所有数据
	CertificateInformationPageDTO::Wrapper listAll(const CertificateInformationPageQuery::Wrapper& query);
};

#endif 
