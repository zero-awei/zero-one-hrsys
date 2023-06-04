#include "stdafx.h"
#include "EvaluationTypesController.h"
#include "service/evaluationTypes/EvaluationTypeService.h"


PullListVO::Wrapper EvaluationTypesController::execQueryEvaluationTypes()
{
	// 创建返回对象
	auto vo = PullListVO::createShared();

	// 构建示例返回
	/*auto a = ItemDTO::createShared(1, "Yes");
	dto->pullList->push_back(a);
	auto b = ItemDTO::createShared(2, "No");
	dto->pullList->push_back(b);

	auto vo = PullListVO::createShared();
	vo->success(dto);*/

	// TODO: 调用service
	EvaluationTypeService service;
	auto dto = service.listAll();
	vo->success(dto);
	return vo;
}

