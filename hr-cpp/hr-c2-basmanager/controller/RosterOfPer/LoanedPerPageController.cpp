/*
（人员花名册-借调人员-分页查询员工列表（导出本页在前端完成））--luoluo
*/
#include "stdafx.h"
#include "LoanedPerPageController.h"
#include "../../service/RosterOfPer/LoanedPerPageService.h"

LoanedPerPageVO::Wrapper LoanedPerPageController::execQueryLoanedPerPage(const LoanedPerPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	LoanedPerPageService service;
	//// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = LoanedPerPageVO::createShared();
	jvo->success(result);
	return jvo;
}

/*
（人员花名册-借调人员-导出证书（导出本页在前端完成））--未小满
*/
StringJsonVO::Wrapper LoanedPerPageController::execExportLoanedPer(const LoanedPerPageQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	LoanedPerPageService service;
	std::string fileName = service.exportData(query);
	if (fileName.empty()) {
		jvo->fail("导出失败");
	}
	else jvo->success(fileName);

	return jvo;
}
