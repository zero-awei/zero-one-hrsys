#include "stdafx.h"
#include "JobTitleInfoController.h"
#include "service/JobTitleInfo/JobTitleInfo.h"

JobTitleInfoJsonVO::Wrapper JobTitleInfoController::execQueryJobTitle(const JobTitleInfoDTO::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = JobTitleInfoJsonVO::createShared();
	JobTitleInfoService service;
	auto result = service.queryDataDetail(query);
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper JobTitleInfoController::execGetJobTitle(const JobTitleInfoDTO::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	JobTitleInfoService service;
	auto result = service.listAllJobTitle(query);
	if (!result.empty())
		jvo->success(result);
	else
		jvo->fail(result);
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
