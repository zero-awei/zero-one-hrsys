#include "stdafx.h"
#include "retirement.h"


StringJsonVO::Wrapper RetirementController::execQueryTest(const PageQuery::Wrapper & query)
{
	/*auto Dto = RetirementDTO::createShared();
	auto Jvo = RetirementQueryPageJsonVO::createShared();
	Jvo->success(Dto);
	return Jvo;*/
	auto vo = StringJsonVO::createShared();
	vo->success("Retirement test qurey1 success");
	return vo;
}
/*
StringJsonVO::Wrapper TestController::execQueryTest1(const PageQuery::Wrapper& query1)
{
	auto vo = StringJsonVO::createShared();
	vo->success("test qurey1 success");
	return vo;
}
*/

/*
Uint64JsonVO::Wrapper TestController::execAddSample(const SampleDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->age || !dto->name || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper TestController::execAddSample1(const RetirementDTO::Wrapper& dto)
Uint64JsonVO::Wrapper RetirementController::execAddSample1(const RetirementDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper RetirementController::execModifySample(const RetirementDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper RetirementController::execRemoveSample(const RetirementDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 响应结果
	return jvo;
}
*/