#include "stdafx.h"
#include "PageQueryBzController.h"

PageQueryVO::Wrapper PageQueryBzController::execPageQueryBz(const PageBzQuery::Wrapper& Query)
{
	auto vo = PageQueryVO::createShared();
	return vo;
}