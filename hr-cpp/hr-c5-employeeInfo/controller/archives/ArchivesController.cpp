#include "stdafx.h"
#include "ArchivesController.h"

ArchivesPageJsonVO::Wrapper ArchivesController::execQueryArchivesinfo(const PageQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = ArchivesPageJsonVO::createShared();
	// 创建分页对象
	auto pdto = ArchivesPageDTO::createShared();
	pdto->addData(ArchivesDTO::createShared());
	pdto->addData(ArchivesDTO::createShared());
	// 响应结果
	vo->success(pdto);
	return vo;
}