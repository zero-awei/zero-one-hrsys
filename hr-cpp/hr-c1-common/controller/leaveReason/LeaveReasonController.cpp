
#include "stdafx.h"
#include "LeaveReasonController.h"
#include "service/leaveReason/LeaveReasonService.h"


PullListVO::Wrapper LeaveReasonController::execQueryLeaveReason()
{
	// 定义返回数据对象
	auto jvo = PullListVO::createShared();
	
	LeaveReasonService service;
	auto dto = service.listAll();

	// 构建成功消息
	jvo->success(dto);
	return jvo;
}
