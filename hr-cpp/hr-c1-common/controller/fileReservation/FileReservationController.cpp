
#include "stdafx.h"
#include "FileReservationController.h"
#include "domain/vo/pullList/PullListVO.h"
#include "uselib/pullListRedis/UseLibRedis.h"
#include "service/fileReservation/FileReservationService.h"
PullListVO::Wrapper FileReservationController::execQueryFileReservation()
{
	auto dto = PullListDTO::createShared();
	FileReservationService service;
	dto = service.listAll();
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}



