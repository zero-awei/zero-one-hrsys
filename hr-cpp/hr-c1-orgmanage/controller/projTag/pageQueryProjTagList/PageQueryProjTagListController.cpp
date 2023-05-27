#include "stdafx.h"
#include "PageQueryProjTagListController.h"
#include "service/projTag/ProjTagService.h"

PageQueryProjTagVO::Wrapper PageQueryProjTagListController::execPageQueryProjTag(const PageProjTagQuery::Wrapper& query)
{
	auto vo = PageQueryProjTagVO::createShared();
	ProjTagService service;
	auto dto = service.listProjTagList(query);
	vo->success(dto);
	return vo;
}