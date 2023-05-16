#include "stdafx.h"
#include "LegalEntityMaiController.h"


LegalEntityMaiPageJsonVO::Wrapper LegalEntityMaiController::execQueryLEM(const LegalEntityMaiQuery::Wrapper& legalEntityMaiQuery)
{
	// 定义一个JsonVO对象
	auto vo = LegalEntityMaiPageJsonVO::createShared();
	// 定义一个分页对象
	auto pageDTO = LegalEntityMaiPageDTO::createShared();
	pageDTO->addData(LegalEntityMaiDTO::createShared("1", "zs"));
	pageDTO->addData(LegalEntityMaiDTO::createShared("2", "ls"));
	// 响应结果
	vo->success(pageDTO);
	return vo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execUpdateLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execAddLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper LegalEntityMaiController::execRemoveLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 响应结果
	return jvo;
}

