/*
（人员花名册-人员花名册-分页查询员工列表）--洛洛
*/
#include "stdafx.h"
#include "EmployeePageController.h"
#include "../../service/RosterOfPer/EmployeePageService.h"

EmployeePageJsonVO::Wrapper EmployeePageController::execQueryEmployeePage(const EmployeePageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	EmployeePageService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = EmployeePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
