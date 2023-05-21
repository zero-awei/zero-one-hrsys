#include "stdafx.h"
#include "ArchivesLevelsController.h"

ArchivesListVO::Wrapper ArchivesLevelsController::execQueryArchivesLevels() {
	auto dto = ArchivesLevelsListDTO::createShared();
	auto vo = ArchivesListVO::createShared();

	auto upLevels = ArchivesLevelsDTO::createShared("ÉÏ²ã");
	auto midLevels = ArchivesLevelsDTO::createShared("ÖÐ²ã");
	auto downLevels = ArchivesLevelsDTO::createShared("ÏÂ²ã");

	dto->levelsList->push_back(upLevels);
	dto->levelsList->push_back(midLevels);
	dto->levelsList->push_back(downLevels);

	return vo;
}