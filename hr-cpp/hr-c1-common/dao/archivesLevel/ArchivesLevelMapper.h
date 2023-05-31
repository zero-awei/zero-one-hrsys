//2023年5月27日
//作者：狗皮电耗子
//档案室层级下拉列表的数据库匹配映射
#pragma once
#ifndef _ARCHIVES_LEVEL_MAPPER_
#define _ARCHIVES_LEVEL_MAPPER_

#include "Mapper.h"
#include "domain/do/archivesLevel/ArchivesLevelDO.h"

class ArchivesLevelMapper : public Mapper<ArchivesLevelDO> 
{
public:
	ArchivesLevelDO mapper(ResultSet* result) const override
	{
		ArchivesLevelDO archivelsLevelsData;
		archivelsLevelsData.setArchiveslevel(result->getString(1));
		return archivelsLevelsData;
	}
};


#endif // !_ARCHIVES_LEVEL_MAPPER_
