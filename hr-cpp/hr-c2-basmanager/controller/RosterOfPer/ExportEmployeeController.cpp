/*
（人员花名册-人员花名册-导出员工（导出本页在前端完成））--luoluo
*/
#include "stdafx.h"
#include "ExportEmployeeController.h"

#include "../../service/RosterOfPer/ExportEmployeeService.h"

ExportEmployeeJsonVO::Wrapper ExportEmployeeController::execExportEmployee(const ExportEmployeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	//ExportEmployeeService service;
	// 查询数据
	//auto result = service.listAll(query);
	// 响应结果
	auto jvo = ExportEmployeeJsonVO::createShared();
	//jvo->success(result);
	return jvo;
}
