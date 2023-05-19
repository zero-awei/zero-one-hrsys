#include "stdafx.h"
#include "ScientificController.h"

ScientificJsonVO::Wrapper ScientificController::execQueryScientific(const ScientificViewQuery::Wrapper& query) {
	// 创建响应对象
	auto vo = ScientificJsonVO::createShared();
	// 响应结果
	vo->success(ScientificDTO::Wrapper::createShared());
	return vo;
}

Uint64JsonVO::Wrapper ScientificController::execModifyScientific(const ScientificDTO::Wrapper& dto)
{
	// 创建响应对象
	auto vo = Uint64JsonVO::createShared();
	// 响应结果
	vo->success(2);
	return vo;
}

StringJsonVO::Wrapper ScientificController::execDownloadScientific(const ScientificDownloadQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = StringJsonVO::createShared();
	// 响应结果
	vo->success("Download-Link");
	return vo;
}