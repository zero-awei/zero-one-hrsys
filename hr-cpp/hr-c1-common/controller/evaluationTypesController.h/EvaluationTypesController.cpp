#include "stdafx.h"
#include "EvaluationTypesController.h"


PullListVO::Wrapper EvaluationTypesController::execQueryEvaluationTypes()
{
	auto dto = PullListDTO::createShared();
	auto a = ItemDTO::createShared(1, "Yes");
	dto->pullList->push_back(a);
	auto b = ItemDTO::createShared(2, "No");
	dto->pullList->push_back(b);

	auto vo = PullListVO::createShared();
	vo->success(dto);
	// TODO: µ÷ÓÃservice
	return vo;
}

