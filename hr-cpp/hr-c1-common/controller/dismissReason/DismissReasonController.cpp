
#include "stdafx.h"
#include "DismissReasonController.h"
#include "service/leaveAndDismissReason/LeaveAndDismissReasonService.h"

PullListVO::Wrapper DismissReasonController::execQueryDismissReason()
{
	// 定义返回数据对象
	auto jvo = PullListVO::createShared();
	LeaveAndDismissReasonService service;
	auto dto = service.listAll();
	// 构建成功消息
	jvo->success(dto);
	return jvo;
}
