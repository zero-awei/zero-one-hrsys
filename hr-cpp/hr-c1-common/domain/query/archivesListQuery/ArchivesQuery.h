#pragma once
#ifndef _ARCHIVES_QUERY_
#define _ARCHIVES_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ArchivesQuery : public oatpp::DTO
{
	DTO_INIT(ArchivesQuery, oatpp::DTO);

	DTO_FIELD(String, levels);
	DTO_FIELD_INFO(levels) {
		info->description = ZH_WORDS_GETTER("common.get.archiveslevels");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ARCHIVES_QUERY_
