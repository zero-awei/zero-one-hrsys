#pragma once
#ifndef _ARCHIVES_LEVELS_DTO_
#define _ARCHIVES_LEVELS_DTO_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class ArchivesLevelsDTO : public oatpp::DTO
{
	DTO_INIT(ArchivesLevelsDTO, DTO);

	DTO_FIELD(String, archiveslevels);
	DTO_FIELD_INFO(archiveslevels) {
		info->description = ZH_WORDS_GETTER("archives.levels");
	}
public:
	ArchivesLevelsDTO()
	{
		archiveslevels = "";
	}

	ArchivesLevelsDTO(String levels)
	{
		archiveslevels = levels;
	}
};

class ArchivesLevelsListDTO : public oatpp::DTO
{
	DTO_INIT(ArchivesLevelsListDTO, DTO);
	DTO_FIELD_INFO(levelsList) {
		info->description = ZH_WORDS_GETTER("common.get.list");
	}
	DTO_FIELD(List<ArchivesLevelsDTO::Wrapper>, levelsList) = {};
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_ARCHIVES_LEVELS_DTO_
