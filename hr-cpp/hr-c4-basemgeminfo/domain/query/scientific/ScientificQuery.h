#pragma once
#ifndef _SCIENTIFICQUERY_H_
#define _SCIENTIFICQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ScientificViewQuery : public oatpp::DTO
{
	DTO_INIT(ScientificViewQuery, DTO);

	// 科研成果标识(主键)
	DTO_FIELD(String, PIMRESEARCHFINDINGSID);
	DTO_FIELD_INFO(PIMRESEARCHFINDINGSID) {
		info->description = ZH_WORDS_GETTER("scientific.PIMRESEARCHFINDINGSID");
	}
};

class ScientificDownloadQuery : public oatpp::DTO
{
	DTO_INIT(ScientificDownloadQuery, DTO);

	// 科研成果人员信息标识
	DTO_FIELD(String, PIMPERSONID);
	DTO_FIELD_INFO(PIMPERSONID) {
		info->description = ZH_WORDS_GETTER("military.PIMPERSONID");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SCIENTIFICQUERY_H_
