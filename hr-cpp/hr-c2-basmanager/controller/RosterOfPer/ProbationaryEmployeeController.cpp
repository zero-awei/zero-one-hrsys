#include "stdafx.h"
#include "ProbationaryEmployeeController.h"
#include "../../service/RosterOfPer/ProbationaryEmployeeService.h"
/**
 *  基础管理 —— 人员花名册 —— 试用员工 —— 楚孟献
 */
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

StringJsonVO::Wrapper ProbationaryEmployeeController::execExportProbationaryEmployee(const ProbationaryEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();

	ProbationaryEmployeeService Service;

	auto result = Service.exportData(query);
	jvo->success(result);

	return jvo;
}