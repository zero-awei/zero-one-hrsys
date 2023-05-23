#include "stdafx.h"
#include "PageQueryProjTagListController.h"

PageQueryVO::Wrapper PageQueryProjTagListController::execPageQueryProjTag(const PageProjTagQuery::Wrapper& query)
{
	auto vo = PageQueryVO::createShared();
	return vo;
}