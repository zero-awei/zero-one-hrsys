#include "stdafx.h"
#include "JobTitleInfoController.h"
#include "service/JobTitleInfo/JobTitleInfo.h"

JTQueryJsonVO::Wrapper JobTitleInfoController::execQueryJobTitle(const JobTitleDTO::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = JTQueryJsonVO::createShared();
	JobTitleInfoService service;
	auto result = service.queryDataDetail(query);
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper JobTitleInfoController::execGetJobTitle(const JobTitleDTO::Wrapper& query, const PayloadDTO& payload)
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

Uint64JsonVO::Wrapper JobTitleInfoController::execModifyJobTitle(const JobTitleDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	JobTitleInfoService service;
	auto resBool = service.updateData(dto);
	if (resBool)
		jvo->success(resBool);
	else
		jvo->fail(resBool);
	return jvo;
}
