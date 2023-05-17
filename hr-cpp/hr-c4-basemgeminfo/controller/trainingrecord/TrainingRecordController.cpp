#include "stdafx.h"
#include "TrainingRecordController.h"

//@Author: Diaukray

StringJsonVO::Wrapper TrainingRecordController::execQueryTest(const PageQuery::Wrapper& query)
{
	
	auto vo = StringJsonVO::createShared();
	vo->success("TrainingRecord PageQuery Success");
	return vo;

}
