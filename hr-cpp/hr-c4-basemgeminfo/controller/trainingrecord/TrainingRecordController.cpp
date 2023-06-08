#include "stdafx.h"
#include "TrainingRecordController.h"
#include "../../service/trainingrecord/TrainingRecordService.h"

//@Author: Diaukray

TrainingRecordPageJsonVO::Wrapper TrainingRecordController::execQueryTrainingRecord(const TrainingRecordPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	TrainingRecordService service;
	// 查询数据
	auto result = service.listAll(query);
	//// 响应结果
	auto jvo = TrainingRecordPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}