
#include "stdafx.h"
#include "FileStatusController.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "service/fileStatus/FileStatusService.h"
PullListVO::Wrapper FileStatusController::execQueryFileStatus()
{
	auto dto = PullListDTO::createShared();
	FileStatusService service;
	dto = service.listAll();
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}
