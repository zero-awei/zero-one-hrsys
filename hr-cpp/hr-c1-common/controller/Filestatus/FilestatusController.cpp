
#include "stdafx.h"
<<<<<<< HEAD
#include "FileStatusController.h"
=======
#include "FilestatusController.h"
>>>>>>> 5e5d758661078be8d67150db2b1b28256751a4a6

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
