/**
 *  基础管理 —— 人员花名册 —— 离职员工 —— 楚孟献
 */

#include "stdafx.h"
#include "FormerEmployeesController.h"
#include "../../service/RosterOfPer/FormerEmployeesService.h"

FormerEmployeesPageJsonVO::Wrapper FormerEmployeesController::execQueryFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	FormerEmployeesService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = FormerEmployeesPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper FormerEmployeesController::execExportFormerEmployees(const FormerEmployeesQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 响应结果
	auto jvo = StringJsonVO::createShared();

	FormerEmployeesService service;
	
	auto result = service.exportData(query);

	jvo->success(result);
	return jvo;
}