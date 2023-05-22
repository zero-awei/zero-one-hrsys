#include "stdafx.h"
#include "CertificateController.h"

CertificatePageJsonVO::Wrapper CertificateController::execQueryCertificate(const CertificateQuery::Wrapper& query)
{
	auto vo = CertificatePageJsonVO::createShared();
	// 创建分页对象
	auto pdto = CertificatePageDTO::createShared();
	pdto->addData(CertificateDTO::createShared("1", "zs"));
	pdto->addData(CertificateDTO::createShared("2", "ls"));
	// 响应结果
	vo->success(pdto);
	return vo;
}

Uint64JsonVO::Wrapper CertificateController::execAddCertificate(const CertificateDTO::Wrapper& dto)
{
	// 创建响应对象
	auto vo = Uint64JsonVO::createShared();
	// 响应结果
	vo->success(2);
	return vo;
}
Uint64JsonVO::Wrapper CertificateController::execDelCertificate(const CertificateDTO::Wrapper& dto)
{
	auto vo = Uint64JsonVO::createShared();
	// 响应结果
	vo->success(2);
	return vo;
}
Uint64JsonVO::Wrapper CertificateController::execModifyCertificate(const CertificateDTO::Wrapper& dto)
{
	auto vo = Uint64JsonVO::createShared();
	// 响应结果
	vo->success(2);
	return vo;
}
