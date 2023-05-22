#include "stdafx.h"
#include "CertificateInformationController.h"
#include "../../service/certificate-information/certificate-information/CertificateInformationService.h"
//定义证书分页查询接口函数execQueryCertificateInformation
CertificateInformationPageJsonVO::Wrapper CertificateInformationController::execQueryCertificateInformation(const CertificateInformationPageQuery::Wrapper& query, const PayloadDTO& payload)
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