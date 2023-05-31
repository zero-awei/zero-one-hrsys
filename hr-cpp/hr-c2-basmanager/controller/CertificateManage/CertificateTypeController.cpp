#include "stdafx.h"
#include "CertificateTypeController.h"
#include "../../service/CertificateManage/CertificateTypeService.h"
/**
 * 证书类型查询功能点，搜索框使用--(证书管理-证书类型)--weixiaoman
 */
CertificateTypePageJsonVO::Wrapper CertificateTypeController::execQueryCertificateType(const CertificateTypeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	CertificateTypeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CertificateTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
