#include "stdafx.h"
#include "BlacklistController.h"

BlacklistPageJsonVO::Wrapper BlacklistController::execQueryBlacklist(const BlacklistQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = BlacklistPageJsonVO::createShared();
	// 创建分页对象
	auto pdto = BlacklistPageDTO::createShared();
	pdto->addData(BlacklistDTO::createShared());
	pdto->addData(BlacklistDTO::createShared());
	// 响应结果
	vo->success(pdto);
	return vo;
}