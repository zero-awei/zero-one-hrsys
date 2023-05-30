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
}

LanguageJsonVO::Wrapper LanguageCompetenceController::execQueryOneLanguage(const LanguageQuery::Wrapper& query, const PayloadDTO& payload)
{
	//定义一个Service
	LanguageService service;
	//查询数据
	auto result = service.queryOneDataById(query);
	//响应结果
	auto jvo = LanguageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Int32JsonVO::Wrapper LanguageCompetenceController::execAddLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//定义一个返回数据对象
	auto jvo = Int32JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->personID || !dto->languageType || !dto->languageLevel) {
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//有效值校验
	if (dto->personID->empty() || dto->languageType->empty() || dto->languageLevel->empty()) {
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	LanguageService service;
	// 执行数据新增
	int count = service.saveData(dto);
	if (count > 0) {
		jvo->success(Int32(count));
	}
	else
	{
		jvo->fail(Int32(count));
	}
	//响应结果
	return jvo;
}

BooleanJsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//定义一个返回对象
	auto jvo = BooleanJsonVO::createShared();
	// 参数校验
	if (!dto->languageAbilityID)
	{
		jvo->init(false, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	LanguageService service;
	// 执行数据删除
	if (service.removeData(dto->languageAbilityID.getValue({}))) {
		jvo->success(true);
	}
	else
	{
		jvo->fail(false);
	}
	// 响应结果
	return jvo;
}

BooleanJsonVO::Wrapper LanguageCompetenceController::execUpdateLanguage(const LanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//定义一个返回对象
	auto jvo = BooleanJsonVO::createShared();
	//参数校验
	if (!dto->languageAbilityID) {
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
