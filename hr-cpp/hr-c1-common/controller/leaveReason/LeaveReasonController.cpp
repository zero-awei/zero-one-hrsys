
#include "stdafx.h"
#include "LeaveReasonController.h"
#include "service/leaveReason/LeaveReasonService.h"
PullListVO::Wrapper LeaveReasonController::execQueryLeaveReason()
{
	// 定义返回数据对象
	auto jvo = PullListVO::createShared();

	// 定义一个Service
	LeaveReasonService service;

	// 执行查询
	auto result = service.listAll();

	// 构建成功消息
	jvo->success(result);
	return jvo;
}
