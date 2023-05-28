#include "stdafx.h"
#include "RewardAndPunishController.h"

RewardAndPunishJsonVO::Wrapper RewardAndPunishController::execQueryRewardAndPunish(const RewardAndPunishViewQuery::Wrapper& query) {
	// 创建响应对象
	auto vo = RewardAndPunishJsonVO::createShared();
	// 响应结果
	vo->success(RewardAndPunishDTO::Wrapper::createShared());
	return vo;
}

Uint64JsonVO::Wrapper RewardAndPunishController::execModifyRewardAndPunish(const RewardAndPunishDTO::Wrapper& dto)
{
	// 创建响应对象
	auto vo = Uint64JsonVO::createShared();
	// 响应结果
	vo->success(2);
	return vo;
}

StringJsonVO::Wrapper RewardAndPunishController::execDownloadRewardAndPunish(const RewardAndPunishDownloadQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = StringJsonVO::createShared();
	// 响应结果
	vo->success("Download-Link");
	return vo;
}