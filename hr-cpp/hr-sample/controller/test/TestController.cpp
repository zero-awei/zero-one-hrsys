#include "stdafx.h"
#include "TestController.h"


StringJsonVO::Wrapper TestController::execQueryTest(const PageQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	vo->success("test query success");
	return vo;
}