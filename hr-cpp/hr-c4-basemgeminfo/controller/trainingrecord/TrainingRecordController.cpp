#include "stdafx.h"
#include "TrainingRecordController.h"

StringJsonVO::Wrapper TrainingRecordController::execQueryTest(const PageQuery::Wrapper& query)
{
	
	auto vo = StringJsonVO::createShared();
	vo->success("TrainingRecord Query Success");
	return vo;

}
