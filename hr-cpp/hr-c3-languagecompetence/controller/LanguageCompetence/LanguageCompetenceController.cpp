#include "stdafx.h"
#include "LanguageCompetenceController.h"
#include "../../service/Language/LanguageService.h"

/**
 * 实现语言能力增删查改模块
 * 负责人：君
 */
LanguagePageJsonVO::Wrapper LanguageCompetenceController::execQueryLanguage(const LanguagePageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	LanguageService service;
	//查询数据
	auto result = service.listAll(query);
	//响应结果
	auto jvo = LanguagePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//auto jvo = StringJsonVO::createShared();
	//jvo->success("query language competence success");
	//return jvo;
}

LanguageJsonVO::Wrapper LanguageCompetenceController::execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload)
{
	//定义一个Service
	LanguageService service;
	//查询数据
	auto result = service.queryOneData(query);
	//响应结果
	auto jvo = LanguageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	/*auto jvo = StringJsonVO::createShared();
	jvo->success("query language competence success");
	return jvo;*/
}

Uint64JsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//定义一个返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->personID || !dto->languageType || !dto->languageLevel) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//有效值校验
	if (dto->languageType->empty() || dto->languageLevel->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	LanguageService service;
	// 执行数据新增
	uint64_t count = service.saveData(dto);
	if (count > 0) {
		jvo->success(UInt64(count));
	}
	else
	{
		jvo->fail(UInt64(count));
	}
	//响应结果
	return jvo;
}
//StringJsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload) 
//{
//	auto jvo = StringJsonVO::createShared();
//	jvo->success("add language competence success");
//	return jvo;
//
//}

BooleanJsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//定义一个返回对象
	auto jvo = BooleanJsonVO::createShared();
	// 参数校验
	if (!dto->personID)
	{
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	LanguageService service;
	// 执行数据删除
	if (service.removeData(dto->personID.getValue(0),dto->languageType.getValue(0))) {
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// 响应结果
	return jvo;
}
//StringJsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	auto jvo = StringJsonVO::createShared();
//	jvo->success("remove language competence success");
//	return jvo;
//}

BooleanJsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//定义一个返回对象
	auto jvo = BooleanJsonVO::createShared();
	//参数校验
	if (!dto->personID) {
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}
	//定义一个Service
	LanguageService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// 响应结果
	return jvo;
}
//StringJsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	auto jvo = StringJsonVO::createShared();
//	jvo->success("update language competence success");
//	return jvo;
//}