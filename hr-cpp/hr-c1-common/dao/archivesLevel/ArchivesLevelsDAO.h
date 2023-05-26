//档案室层级下拉列表
//作者：狗皮电耗子
//2023年5月26日
#pragma once
#ifndef _ARCHIVES_LEVEL_DAO_
#define _ARCHIVES_LEVEL_DAO_

#include "BaseDAO.h"
#include "../../domain/do/archivesLevel/ArchivesLevelDO.h"

class ArchivesLevelsDAO
{
	list<ArchivesLevelDO> getArchivesLevels();
};

#endif // !_ARCHIVES_LEVEL_DAO_



