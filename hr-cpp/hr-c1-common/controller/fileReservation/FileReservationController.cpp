
#include "stdafx.h"
#include "FileReservationController.h"
#include "domain/vo/pullList/PullListVO.h"

PullListVO::Wrapper FileReservationController::execQueryFileReservation()
{
	auto dto = PullListDTO::createShared();
	auto localbase = ItemDTO::createShared(10, ZH_WORDS_GETTER("fileReservation.localbase"));
	auto enterbase = ItemDTO::createShared(20, ZH_WORDS_GETTER("fileReservation.enterbase"));
	auto other = ItemDTO::createShared(30, ZH_WORDS_GETTER("fileReservation.other"));
	dto->pullList->push_back(localbase);
	dto->pullList->push_back(enterbase);
	dto->pullList->push_back(other);
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}



