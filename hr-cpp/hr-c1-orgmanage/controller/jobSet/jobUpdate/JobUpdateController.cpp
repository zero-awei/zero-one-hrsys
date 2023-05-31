#include "stdafx.h"
#include "JobUpdateController.h"
#include "service/jobSet/jobUpdateService/JobUpdateService.h"
#include "SimpleDateTimeFormat.h"

JobUpdateJsonVO::Wrapper JobUpdateController::execUpdateJobinfo(const JobUpdateDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = JobUpdateJsonVO::createShared();
	dto->updateMan = payload.getUsername();
	dto->updateDate== SimpleDateTimeFormat::format();
	JobUpdateService service;
	if (service.uodateJobInfo(dto)) {
		jvo->success(dto);
	}
	else {
		jvo->fail(dto);
	}
	// 响应结果
	return jvo;
}