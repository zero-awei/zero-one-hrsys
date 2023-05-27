#include "stdafx.h"
#include "ProbationaryEmployeeController.h"
#include "../../service/RosterOfPer/ProbationaryEmployeeService.h"

ProbationaryEmployeePageJsonVO::Wrapper ProbationaryEmployeeController::execQueryProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ProbationaryEmployeeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ProbationaryEmployeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ProbationaryEmployeePageJsonVO::Wrapper ProbationaryEmployeeController::execListProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = ProbationaryEmployeePageJsonVO::createShared();

	return jvo;
}