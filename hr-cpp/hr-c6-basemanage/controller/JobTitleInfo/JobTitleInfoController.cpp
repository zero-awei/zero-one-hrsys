#include "stdafx.h"
#include "JobTitleInfoController.h"

JobTitleInfoJsonVO::Wrapper JobTitleInfoController::execQueryJobTitle(const JobTitleInfoDTO::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = JobTitleInfoJsonVO::createShared();
	auto result = JobTitleInfoDTO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper JobTitleInfoController::execGetJobTitle(const JobTitleInfoDTO::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	String result;
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper JobTitleInfoController::execModifyJobTitle(const JobTitleInfoDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	UInt64 res_id{};
	jvo->success(res_id);
	// 响应结果
	return jvo;
}
