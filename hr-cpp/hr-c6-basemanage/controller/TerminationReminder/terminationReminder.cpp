#include <stdafx.h>
#include "terminationReminder.h"


StringJsonVO::Wrapper TerminationReminderController::execQueryLimit(const PageQuery::Wrapper& query)
{
	// 定义一个Service
	//SampleService service;
	// 查询数据
	//auto result = service.listAll(query);
	auto vo = StringJsonVO::createShared();
	vo->success("success");
	return vo;
}

StringJsonVO::Wrapper TerminationReminderController::execExportAll(const PageQuery::Wrapper& query)
{
	auto vo = StringJsonVO::createShared();
	vo->success("success");
	return vo;
}
