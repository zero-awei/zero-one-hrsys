#include "stdafx.h"
#include "ArchivesController.h"
#include "../../service/archives/ArchivesService.h"

ArchivesPageJsonVO::Wrapper ArchivesController::execQueryTest(const ArchivesQuery::Wrapper& query) {
	// 定义一个Service
	ArchivesService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ArchivesPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}