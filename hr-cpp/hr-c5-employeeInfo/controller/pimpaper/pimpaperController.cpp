#include "stdafx.h"
#include "pimpaperController.h"

PimpaperPageJsonVO::Wrapper PimpaperController::execQueryPimpaper(const PimpaperQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = PimpaperPageJsonVO::createShared();
	// 创建分页对象
	auto pdto = PimpaperPageDTO::createShared();
	pdto->addData(PimpaperDTO::createShared(1, "page1"));
	pdto->addData(PimpaperDTO::createShared(2, "page2"));
	// 响应结果
	vo->success(pdto);
	return vo;
}

Uint64JsonVO::Wrapper PimpaperController::execAddPimpaper(const PimpaperDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->ygbh || !dto->pimpersonname)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->ygbh < 0 || dto->pimpersonname->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper PimpaperController::execRemovePimpaper(const PimpaperDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->ygbh || dto->ygbh <= 0 || !dto->pimpersonname || dto->pimpersonname->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 响应结果
	return jvo;
}
