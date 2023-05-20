#include "stdafx.h"
#include "JobLevelTypeListController.h"

PullListVO::Wrapper JobLevelTypeListController::execQueryJobLevelType()
{
	auto dto = PullListDTO::createShared();
	auto a = ItemDTO::createShared(1, "A");
	dto->pullList->push_back(a);
	auto b = ItemDTO::createShared(2, "B");
	dto->pullList->push_back(b);

	auto vo = PullListVO::createShared();
	vo->success(dto);

	return vo;
}