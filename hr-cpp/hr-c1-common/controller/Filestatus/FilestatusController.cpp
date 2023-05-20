
#include "stdafx.h"
#include "FilestatusController.h"

PullListVO::Wrapper FileStatusController::execQueryFileStatus()
{
	auto dto = PullListDTO::createShared();
	auto borrowing = ItemDTO::createShared(1, ZH_WORDS_GETTER("fileStatus.borrowing"));
	dto->pullList->push_back(borrowing);
	auto returned = ItemDTO::createShared(2, ZH_WORDS_GETTER("fileStatus.returned"));
	dto->pullList->push_back(returned);
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}
