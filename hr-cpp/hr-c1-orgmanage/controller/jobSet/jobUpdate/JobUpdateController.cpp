#include "stdafx.h"
#include "JobUpdateController.h"
#include "service/jobSet/jobUpdateService/JobUpdateService.h"
#include "SimpleDateTimeFormat.h"

JobUpdateJsonVO::Wrapper JobUpdateController::execUpdateJobinfo(const JobUpdateDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = JobUpdateJsonVO::createShared();

	// 数据校验
	if (!dto->ormPostId || dto->ormPostId->empty())
	{
		jvo->init({}, RS_PARAMS_INVALID);
		return jvo;
	}
	
	JobUpdateService service;
	if (service.updateJobInfo(dto, payload)) {
		jvo->success(dto);
	}
	else {
		jvo->fail(dto);
	}
	// 响应结果
	return jvo;
}