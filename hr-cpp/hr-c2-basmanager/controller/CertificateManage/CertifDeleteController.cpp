/*
（证书管理-证书信息-删除证书（支持批量删除））--洛洛
*/
#include "stdafx.h"
#include "CertifDeleteController.h"
#include "../../service/CertificateManage/DeleteCertifService.h"


StringJsonVO::Wrapper CertifDeleteController::execRemoveCertif(const RemoveCertifDTO::Wrapper& dto)
{
	
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->id)
	{
		jvo->init(string("param err"), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DeleteCertifService service;
	// 执行数据删除
	if (service.removeData(dto->id.getValue(""))) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}