#include "stdafx.h"
#include "MyController.h"

StringJsonVO::Wrapper TestController::execQueryTest(const PageQuery::Wrapper & query)
{
	auto vo = StringJsonVO::createShared();
	vo->success("test qurey success");
	return vo;
}