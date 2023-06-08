/*
* 法人主体设置--删除法人设置(支持批量删除)--pine
*/
#include "stdafx.h"
#include "DeleteLegalEntityController.h"
#include "../../service/LegalEntitySet/DeleteLegalEntityService.h"


StringJsonVO::Wrapper DeleteLegalEntityController::execDeleteLegalEntity(const DeleteLegalEntityDTO::Wrapper& dto)
{

	auto jvo = StringJsonVO::createShared();

	int length = dto->contractsignorgid->size();
	if (length <= 0 || !dto->contractsignorgid) {
		jvo->init(string("param null"), RS_PARAMS_INVALID);
		return jvo;
	}

	for (auto it = dto->contractsignorgid->begin(); it != dto->contractsignorgid->end(); ++it)
	{
		if ((*it)->size() != 36) {//简单判断编号格式是否错误//有一项编号的字符长度为32
			jvo->init(string("param err"), RS_PARAMS_INVALID);
			return jvo;
		}
	}

	stringstream str;
	for (auto it = dto->contractsignorgid->begin(); it != dto->contractsignorgid->end(); ++it) str << (*it).getValue("") << " ";

	if (DeleteLegalEntityService().removeData(dto)) jvo->success(str.str());
	else jvo->fail(str.str());

	return jvo;
}