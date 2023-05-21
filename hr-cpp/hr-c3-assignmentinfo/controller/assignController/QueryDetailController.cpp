#include "stdafx.h"
#include "QueryDetailAssignController.h"


AssignInfoQueryDetailJsonVO::Wrapper QueryDetailAssignController::execAssignQueryDetail(const AssignInfoQueryDetail::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = AssignInfoQueryDetailJsonVO::createShared();
	return jvo;
}

