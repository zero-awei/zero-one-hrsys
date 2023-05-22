
#include "stdafx.h"
#include "LeaveReasonController.h"

PullListVO::Wrapper LeaveReasonController::execQueryLeaveReason()
{
	auto dto = PullListDTO::createShared();
	// 个人原因
	auto personal = ItemDTO::createShared(1, "personal");
	dto->pullList->push_back(personal);
	// 家庭原因
	auto familial = ItemDTO::createShared(2, "familial");
	dto->pullList->push_back(familial);
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}
