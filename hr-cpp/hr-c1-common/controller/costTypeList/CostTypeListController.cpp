#include "stdafx.h"
#include "CostTypeListController.h"
#include "service/costTypeList/CostTypeListService.h"

PullListVO::Wrapper CostTypeListController::execQueryCostType()
{
	/*auto dto = PullListDTO::createShared();
	auto a = ItemDTO::createShared(1, "A");
	dto->pullList->push_back(a);
	auto b = ItemDTO::createShared(2, "B");
	dto->pullList->push_back(b);

	auto vo = PullListVO::createShared();
	vo->success(dto);*/

	auto vo = PullListVO::createShared();
	CostTypeListService service;
	auto dto = service.listAll();
	vo->success(dto);

	return vo;
}