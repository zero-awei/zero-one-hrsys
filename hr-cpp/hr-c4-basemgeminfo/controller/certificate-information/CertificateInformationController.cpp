#include "stdafx.h"
#include "CertificateInformationController.h"
#include "../../service/certificate-information/CertificateInformationService.h"
CertificateInformationPageJsonVO::Wrapper CertificateInformationController::execQuerySample(constCertificateInformationQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	CertificateInformationService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CertificateInformationPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}