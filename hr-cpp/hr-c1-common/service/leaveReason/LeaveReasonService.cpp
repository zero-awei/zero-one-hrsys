
#include "stdafx.h"
#include "LeaveReasonService.h"
#include "dao/leaveReason/LeaveReasonDAO.h"
PullListDTO::Wrapper LeaveReasonService::listAll()
{
	auto ret = PullListDTO::createShared();
	LeaveReasonDAO dao;
	auto result = dao.queryLeaveReasonList();
	int i = 0;
	for (LeaveReasonDO sub : result)
	{
		auto dto = ItemDTO::createShared();
		dto->key = i++;
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, Leavereason);
		ret->pullList->push_back(dto);
	}
	return ret;
}
