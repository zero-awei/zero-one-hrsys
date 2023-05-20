
#include "stdafx.h"
#include "FileReservationController.h"
#include "domain/vo/pullList/PullListVO.h"

PullListVO::Wrapper FileReservationController::execQueryFileReservation()
{
	auto dto = PullListDTO::createShared();
	auto localbase = ItemDTO::createShared(1, ZH_WORDS_GETTER("fileReservation.localbase"));
	auto enterbase = ItemDTO::createShared(2, ZH_WORDS_GETTER("fileReservation.enterbase"));
	auto other = ItemDTO::createShared(3, ZH_WORDS_GETTER("fileReservation.other"));
	dto->pullList->push_back(localbase);
	dto->pullList->push_back(enterbase);
	dto->pullList->push_back(other);
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}


