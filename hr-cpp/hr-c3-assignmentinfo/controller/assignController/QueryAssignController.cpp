#include "stdafx.h"
#include "QueryAssignController.h"
#include "../../service/assignInfo/AssignInfoQueryService.h"

AssignInfoQueryJsonVO::Wrapper QueryAssignController::execAssignQuery(const AssignInfoQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	AssignInfoQueryService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = AssignInfoQueryJsonVO::createShared();
	jvo->success(result);
	return jvo;
}