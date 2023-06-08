/**
 * 挂职人员信息查询--(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
 */
#include "stdafx.h"
#include "TemporaryStaffController.h"
#include "./service/RosterOfPer/TemporaryStaffService.h"
TemporaryStaffPageJsonVO::Wrapper TempStaffController::execQueryTempstaff(const TempStaffQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	TemporaryStaffService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = TemporaryStaffPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper TempStaffController::execExportTempstaff(const TempStaffQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	TemporaryStaffService service;
	std::string fileName = service.exportData(query);
	if (fileName.empty()) {
		jvo->fail("导出失败");
	}
	else jvo->success(fileName);

	return jvo;
}

