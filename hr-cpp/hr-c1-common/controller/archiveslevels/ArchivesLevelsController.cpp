#include "stdafx.h"
#include "ArchivesLevelsController.h"

ArchivesListVO::Wrapper ArchivesLevelsController::execQueryArchivesLevels() {
	auto dto = ArchivesLevelsListDTO::createShared();
	auto vo = ArchivesListVO::createShared();

	auto upLevels = ArchivesLevelsDTO::createShared("上层");
	auto midLevels = ArchivesLevelsDTO::createShared("中层");
	auto downLevels = ArchivesLevelsDTO::createShared("下层");

	dto->levelsList->push_back(upLevels);
	dto->levelsList->push_back(midLevels);
	dto->levelsList->push_back(downLevels);

	vo->success(dto);

	return vo;
}