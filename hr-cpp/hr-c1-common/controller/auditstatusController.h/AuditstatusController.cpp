#include "stdafx.h"
#include "AuditStatusController.h"


PullListVO::Wrapper AuditStatusController::execQueryAuditStatus()
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

