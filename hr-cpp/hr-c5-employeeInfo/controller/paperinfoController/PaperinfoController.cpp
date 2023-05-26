#include "stdafx.h"
#include "PaperinfoController.h"
#include "../../service/paperinfo/PaperinfoService.h"

PaperPageJsonVO::Wrapper PaperinfoController::execQueryPaperinfo(const PageQuery::Wrapper& query)
{
	// 定义一个Service
	PaperinfoService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PaperPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper PaperinfoController::execModifyPaperinfo(const PaperDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->fbsj || !dto->cbs || !dto->kwqs || !dto->fj
		|| !dto->grzlwzzzdpm || !dto->kwmc || !dto->pimpapername)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->fbsj->empty() || dto->cbs->empty() || dto->kwqs->empty() ||
		dto->fj->empty() || dto->grzlwzzzdpm < 0 || dto->kwmc->empty() ||
		dto->pimpapername->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	PaperinfoService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}


Uint64JsonVO::Wrapper PaperinfoController::execAddPaperinfo(const PaperDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}

Uint64JsonVO::Wrapper PaperinfoController::execRemovePaperinfo(const PaperDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验

	return jvo;
}