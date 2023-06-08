#include "stdafx.h"
#include "RewardAndPunishController.h"
#include "../../service/rewardandpunish/RewardAndPunishService.h"
#include <iostream>

RewardAndPunishJsonVO::Wrapper RewardAndPunishController::execQueryRewardAndPunish(const RewardAndPunishDetailQuery::Wrapper& query) {
	// 响应结果
	auto jvo = RewardAndPunishJsonVO::createShared();
	// 定义一个Service
	RewardAndPunishService service;
	// 查询数据
	auto result = service.listDetail(query);
	if (result->PIMREWARDPUNISHMENTID.getValue("").empty()) {
		std::cout << "No details were found" << std::endl;
		jvo->fail(result);
	}
	else {
		jvo->success(result);
	}
	return jvo;
}

StringJsonVO::Wrapper RewardAndPunishController::execModifyRewardAndPunish(const RewardAndPunishDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	//参数校验
	if (dto->PIMREWARDPUNISHMENTID.getValue("").empty())
	{
		jvo->init(String("PIMREWARDPUNISHMENTID must be not null"), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	RewardAndPunishService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->PIMREWARDPUNISHMENTID);
	}
	else
	{
		jvo->fail(dto->PIMREWARDPUNISHMENTID);
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper RewardAndPunishController::execDownloadRewardAndPunish(const RewardAndPunishDownloadQuery::Wrapper& query)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	string filedName = RewardAndPunishService().download(query);
	// 响应结果
	if (filedName.empty()) {
		jvo->fail("download failed!");
	}
	else {
		jvo->success(filedName);
	}
	return jvo;
}
