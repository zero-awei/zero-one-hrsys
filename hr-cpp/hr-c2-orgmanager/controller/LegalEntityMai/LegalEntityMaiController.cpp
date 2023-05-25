#include "stdafx.h"
#include "LegalEntityMaiController.h"
#include "service/LegalEntityMai/LegalEntityMaiService.h"


LegalEntityMaiPageJsonVO::Wrapper LegalEntityMaiController::execQueryLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	//// 定义一个Service
	//LegalEntityMaiService service;
	//// 查询数据
	//auto result = service.listAll(query);
	//// 响应结果
	//auto jvo = LegalEntityMaiPageJsonVO::createShared();
	//jvo->success(result);
	//return jvo;
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
	//// 定义返回数据对象
	//auto jvo = Uint64JsonVO::createShared();
	//// 参数校验
	//if (dto->ORMSIGNORGID == "") {

	//}
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

BooleanJsonVO::Wrapper LegalEntityMaiController::execImportLEM(const LegalEntityMaiDTO::Wrapper& dto)
{
	return BooleanJsonVO::createShared();
}

BooleanJsonVO::Wrapper LegalEntityMaiController::execExportLEM(const LegalEntityMaiQuery::Wrapper& query)
{
	return BooleanJsonVO::createShared();
}

