#include "stdafx.h"
#include "LanguageCompetenceController.h"
#include "../../service/Language/LanguageService.h"

StringJsonVO::Wrapper LanguageCompetenceController::execQueryLanguage(const LanguagePageQuery::Wrapper& query, const PayloadDTO& payload)
{
	//// 定义一个Service
	//LanguageService service;
	////查询数据
	//auto result = service.listAll(query);
	////响应结果
	//auto jvo = StringJsonVO::createShared();
	//jvo->success(result);
	//return jvo;
	auto jvo = StringJsonVO::createShared();
	jvo->success("query language competence success");
	return jvo;
}

StringJsonVO::Wrapper LanguageCompetenceController::execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("query language competence success");
	return jvo;
}

//Uint64JsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	//定义一个返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	// 非空校验
//	if (!dto->id || !dto->languageType || !dto->languageLevel) {
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	//有效值校验
//	if (dto->id < 1 || dto->languageType->empty() || dto->languageLevel->empty()) {
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	LanguageService service;
//	// 执行数据新增
//	uint64_t id = service.saveData(dto);
//	if (id > 0) {
//		jvo->success(UInt64(id));
//	}
//	else
//	{
//		jvo->fail(UInt64(id));
//	}
//	//响应结果
//	return jvo;
//}
StringJsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload) 
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("add language competence success");
	return jvo;

}

//Uint64JsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	//定义一个返回对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	if (!dto->id || dto->id < 1)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	LanguageService service;
//	// 执行数据删除
//	if (service.removeData(dto->id.getValue(0))) {
//		jvo->success(dto->id);
//	}
//	else
//	{
//		jvo->fail(dto->id);
//	}
//	// 响应结果
//	return jvo;
//}
StringJsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("remove language competence success");
	return jvo;
}

//Uint64JsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
//{
//	//定义一个返回对象
//	auto jvo = Uint64JsonVO::createShared();
//	//参数校验
//	if (!dto->id || dto->id < 1) {
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	//定义一个Service
//	LanguageService service;
//	// 执行数据修改
//	if (service.updateData(dto)) {
//		jvo->success(dto->id);
//	}
//	else
//	{
//		jvo->fail(dto->id);
//	}
//	// 响应结果
//	return jvo;
//}
StringJsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	jvo->success("update language competence success");
	return jvo;
}