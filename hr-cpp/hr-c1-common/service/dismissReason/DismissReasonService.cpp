
#include "stdafx.h"
#include "DismissReasonService.h"
#include "dao/dismissReason/DismissReasonDAO.h"

PullListDTO::Wrapper DismissReasonService::listAll()
{
	auto ret = PullListDTO::createShared();
	DismissReasonDAO dao;
	auto result = dao.queryDismissReasonList();
	int i = 0;
	for (DismissReasonDO sub : result)
	{
		auto dto = ItemDTO::createShared();
		dto->key = i++;
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, val, Dismissreason);
		ret->pullList->push_back(dto);
	}
	return ret;
}
