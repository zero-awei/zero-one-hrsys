#include"stdafx.h"
#include"test_Controller.h"

StringJsonVO::Wrapper TestController::execQueryTest(const PageQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	vo->success("test query success");
	return vo;
}
