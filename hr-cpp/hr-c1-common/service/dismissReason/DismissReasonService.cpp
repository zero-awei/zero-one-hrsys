
#include "stdafx.h"
#include "DismissReasonService.h"
#include "dao/dismissReason/DismissReasonDAO.h"

PullListDTO::Wrapper DismissReasonService::listAll()
{
	auto ret = PullListDTO::createShared();
	DismissReasonDAO dao;
	auto result = dao.queryDismissReasonList();
	for (DismissReasonDO sub : result)
	{
		auto dto = ItemDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, Dismissreason, key, Code);
		ret->pullList->push_back(dto);
	}
	return ret;
}
