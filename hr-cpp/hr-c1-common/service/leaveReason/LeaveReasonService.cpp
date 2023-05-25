
#include "stdafx.h"
#include "LeaveReasonService.h"
#include "dao/leaveReason/LeaveReasonDAO.h"
PullListDTO::Wrapper LeaveReasonService::listAll()
{
	auto ret = PullListDTO::createShared();
	LeaveReasonDAO dao;
	auto result = dao.queryLeaveReasonList();
	for (LeaveReasonDO sub : result)
	{
		auto dto = ItemDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, Leavereason, key, Code);
		ret->pullList->push_back(dto);
	}
	return ret;
}
