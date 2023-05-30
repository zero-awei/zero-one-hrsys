
#include "stdafx.h"
#include "CreateNewCerController.h"
#include "../../service/CertificateManage/CreateNewCerService.h"

Uint64JsonVO::Wrapper CreateNewCerController::execAddNewCer(const CreateNewCerDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 非空校验
	if (!dto->ygbh || !dto->pimVocationalName)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->ygbh < 0 || dto->pimVocationalName->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 执行数据新增
	CreateNewCerService service;
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}

	return jvo;
}