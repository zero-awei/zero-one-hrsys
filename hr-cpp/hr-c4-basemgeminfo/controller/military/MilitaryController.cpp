#include "stdafx.h"
#include "MilitaryController.h"
#include "../../service/military/MilitaryService.h"

MilitaryJsonVO::Wrapper MilitaryController::execQueryMilitary(const MilitaryDetailQuery::Wrapper& query) {
	// 定义一个Service
	MilitaryService service;
	// 查询数据
	auto result = service.listDetail(query);
	// 响应结果
	auto jvo = MilitaryJsonVO::createShared();
	jvo->success(result);
	return jvo;
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
