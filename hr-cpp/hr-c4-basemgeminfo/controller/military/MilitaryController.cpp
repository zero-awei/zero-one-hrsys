#include "stdafx.h"
#include "MilitaryController.h"

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryQuery::Wrapper& query) {
	// 创建响应对象
	auto vo = MilitaryJsonVO::createShared();
	// 响应结果
	vo->success(MilitaryDTO::Wrapper::createShared());
	return vo;
}