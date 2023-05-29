#include "stdafx.h"
#include "PageQueryBzController.h"

NoDataJsonVO::Wrapper PageQueryBzController::execPageQueryBz(const PageBzQuery::Wrapper& Query)
{
	auto vo = NoDataJsonVO::createShared();
	return vo;
}