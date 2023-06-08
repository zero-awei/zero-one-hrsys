/*
（证书管理-证书信息-删除证书（支持批量删除））--洛洛
*/
#include "stdafx.h"
#include "CertifDeleteController.h"
#include "../../service/CertificateManage/DeleteCertifService.h"

StringJsonVO::Wrapper CertifDeleteController::execRemoveCertif(const RemoveCertifDTO::Wrapper& dto)
{

	auto jvo = StringJsonVO::createShared();

	int length = dto->idByBatch->size();
	if (length <= 0 || !dto->idByBatch) {
		jvo->init(string("param null"), RS_PARAMS_INVALID);
		return jvo;
	}

	for (auto it = dto->idByBatch->begin(); it!=dto->idByBatch->end(); ++it)
	{
		if ((*it)->size()!=36) {//简单判断编号格式是否错误//有一项编号的字符长度为32
			jvo->init(string("param err"), RS_PARAMS_INVALID);
			return jvo;
		}
	}

	stringstream str;
	for (auto it = dto->idByBatch->begin(); it != dto->idByBatch->end(); ++it) str << (*it).getValue("") <<" ";

	if (DeleteCertifService().removeData(dto)) jvo->success(str.str());
	else jvo->fail(str.str());

	return jvo;
}