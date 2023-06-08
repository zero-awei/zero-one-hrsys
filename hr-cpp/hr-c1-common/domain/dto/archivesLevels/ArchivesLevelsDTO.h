#pragma once
#ifndef _ARCHIVES_LEVELS_DTO_
#define _ARCHIVES_LEVELS_DTO_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class ArchivesLevelsDTO : public oatpp::DTO
{
	DTO_INIT(ArchivesLevelsDTO, DTO);

	DTO_FIELD(UInt64, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("archives.code");
	}

	DTO_FIELD(String, archiveslevels);
	DTO_FIELD_INFO(archiveslevels) {
		info->description = ZH_WORDS_GETTER("archives.levels");
	}

public:
	ArchivesLevelsDTO()
	{
		code = -1;
		archiveslevels = "";
	}

	ArchivesLevelsDTO(UInt64 value, String levels)
	{
		code = value;
		archiveslevels = levels;
	}
};

class ArchivesLevelsListDTO : public oatpp::DTO
{
	DTO_INIT(ArchivesLevelsListDTO, DTO);
	DTO_FIELD_INFO(levelsList) {
		info->description = ZH_WORDS_GETTER("common.dto.archiveslist");
	}
	DTO_FIELD(List<ArchivesLevelsDTO::Wrapper>, levelsList) = {};
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_ARCHIVES_LEVELS_DTO_
