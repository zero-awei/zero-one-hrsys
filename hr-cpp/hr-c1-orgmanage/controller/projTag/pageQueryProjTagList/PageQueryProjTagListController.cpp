#include "stdafx.h"
#include "PageQueryProjTagListController.h"

PageQueryProjTagVO::Wrapper PageQueryProjTagListController::execPageQueryProjTag(const PageProjTagQuery::Wrapper& query)
{
	auto vo = PageQueryProjTagVO::createShared();
	return vo;
}