#include <stdafx.h>
#include "terminationReminder.h"


TerminationReminderPageJsonVO::Wrapper TerminationReminderController::execQueryLimit(const TerminationReminderQuery::Wrapper& query)
{
	// 定义一个Service
	TerminationReminderService service;
	// 查询数据
	auto result = service.listAll(query);
	auto vo = TerminationReminderPageJsonVO::createShared();
	vo->success(result);
	return vo;
}

StringJsonVO::Wrapper TerminationReminderController::execExportAll(const TerminationReminderQuery::Wrapper& query)
{
	TerminationReminderService service;
	auto  result = service.exportAll(query);
	auto vo = StringJsonVO::createShared();
	vo->success(result);
	return vo;
}
