#include "stdafx.h"
#include "PatentinfoController.h"
#include "../../service/patentinfo/PatentService.h"

PatentinfoJsonVO::Wrapper PatentinfoController::execQueryPatentinfo(const String& str)
{
	// 定义一个Service
	PatentService service;
	// 查询数据
	auto result = service.listAll(str);
	//创建响应对象
	auto vo = PatentinfoJsonVO::createShared();
	vo->success(result);
	return vo;
}

PatentinfoPageJsonVO::Wrapper PatentinfoController::execQueryPagePatent(const PatentinfoQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = PatentinfoPageJsonVO::createShared();
	// 创建分页对象
	auto pdto = PatentinfoPageDTO::createShared();
	pdto->addData(PatentinfoDTO::createShared("1", "page1"));
	pdto->addData(PatentinfoDTO::createShared("2", "page2"));
	// 响应结果
	vo->success(pdto);
	return vo;
}


Uint64JsonVO::Wrapper PatentinfoController::execModifyPatentinfo(const ModifyPatentinfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->pimpatentid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	PatentService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success({});
	}
	else
	{
		jvo->fail({});
	}
	//jvo->success(dto->pimpatentid);
	return jvo;
}


Uint64JsonVO::Wrapper PatentinfoController::execAddPatent(const PatentinfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->pimpersonid)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->pimpersonid->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper PatentinfoController::execRemovePatent(const PatentinfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->pimpersonid->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 响应结果
	return jvo;
}

