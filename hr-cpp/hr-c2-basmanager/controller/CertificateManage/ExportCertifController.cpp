/*
（证书管理-证书信息-导出证书（导出本页在前端完成））--洛洛
*/
#include "stdafx.h"
#include "ExportCertifController.h"
#include "../../service/CertificateManage/ExportCertifService.h"

ExportCertifJsonVO::Wrapper ExportCertifController::execExportCertif(const ExportCertifQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	// ExportCertifService service;
	// 查询数据
	//auto result = service.listAll(query);
	// 响应结果
	auto jvo = ExportCertifJsonVO::createShared();
	//jvo->success(result);
	return jvo;
}

