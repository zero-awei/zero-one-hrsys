#include "stdafx.h"
#include "LanguageCompetenceController.h"
#include "../../service/language/LanguageService.h"

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
	if (!dto->languageType || !dto->languageLevel) {
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//有效值校验
	if (dto->languageType->empty() || dto->languageLevel->empty()) {
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//获取操作用户ID
	dto->createMan = payload.getId();
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

Int32JsonVO::Wrapper LanguageCompetenceController::execDeleteLanguage(const DeleteLanguageDTO::Wrapper& dto, const PayloadDTO& payload)
{
	//定义一个返回对象
	auto jvo = Int32JsonVO::createShared();
	// 参数校验
	int length = dto->languageAbilityID->size();
	if (length <= 0)
	{
		jvo->init(Int32(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	for (auto it = dto->languageAbilityID->begin(); it != dto->languageAbilityID->end(); it++) {
		if (!(*it)) {
			jvo->init(Int32(-1), RS_PARAMS_INVALID);
			return jvo;
		}
	}
	// 定义一个Service
	LanguageService service;
	// 执行数据删除
	int count = service.removeData(dto);
	if (count > 0) {
		jvo->success(Int32(count));
	}
	else
	{
		jvo->fail(Int32(count));
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
	//获取操作用户ID
	dto->updateMan = payload.getId();
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
