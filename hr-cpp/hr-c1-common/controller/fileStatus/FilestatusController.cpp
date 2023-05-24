
#include "stdafx.h"
#include "FileStatusController.h"


PullListVO::Wrapper FileStatusController::execQueryFileStatus()
{
	auto dto = PullListDTO::createShared();
	auto borrowing = ItemDTO::createShared(10, ZH_WORDS_GETTER("fileStatus.borrowing"));
	dto->pullList->push_back(borrowing);
	auto returned = ItemDTO::createShared(20, ZH_WORDS_GETTER("fileStatus.returned"));
	dto->pullList->push_back(returned);
	auto vo = PullListVO::createShared();
	vo->success(dto);
	return vo;
}
