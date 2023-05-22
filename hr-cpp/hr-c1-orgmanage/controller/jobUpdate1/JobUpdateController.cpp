#include "stdafx.h"
#include "JobUpdateController.h"

JobUpdateJsonVO::Wrapper JobUpdateController::execUpdateJobinfo(const JobUpdateDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = JobUpdateJsonVO::createShared();
	// 参数校验
	if (!dto->index || dto->index <= 0)
	{
		jvo->init(UInt32(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	jvo->success(dto->index);
	
	// 响应结果
	return jvo;
}