#include "stdafx.h"
#include "MilitaryController.h"

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryDetailQuery::Wrapper& query) {
	// 创建响应对象
	auto vo = MilitaryJsonVO::createShared();
	// 响应结果
	vo->success(MilitaryDTO::Wrapper::createShared());
	return vo;
}

Uint64JsonVO::Wrapper MilitaryController::execModifyMilitary(const MilitaryDTO::Wrapper& dto)
{
	// 创建响应对象
	auto vo = Uint64JsonVO::createShared();
	// 响应结果
	vo->success(1);
	return vo;
}

StringJsonVO::Wrapper MilitaryController::execDownloadMilitary(const MilitaryDownloadQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = StringJsonVO::createShared();
	// 响应结果
	vo->success("Download-Link");
	return vo;
}
