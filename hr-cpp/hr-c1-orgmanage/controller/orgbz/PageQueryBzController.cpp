#include "stdafx.h"
#include "PageQueryBzController.h"
#include "service/orgbz/PageQueryBzService.h"

PageQueryBzVO::Wrapper PageQueryBzController::execPageQueryBz(const PageQueryBzQuery::Wrapper& Query)
{
	PageQueryBzService service;
	auto result = service.listPageQueryBz(Query);
	auto jvo = PageQueryBzVO::createShared();
	if (result->rows->size() <= 0) {
		jvo->fail(result);
	}
	else {
		jvo->success(result);
	}
	return jvo;
}