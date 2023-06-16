#pragma once
#ifndef _ARCHIVES_DEL_DTO_
#define _ARCHIVES_DEL_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 档案信息传输对象
 */
class ArchivesDelDTO : public oatpp::DTO
{
	DTO_INIT(ArchivesDelDTO, DTO);
	DTO_FIELD(List<String>, deleteById) = {};
	DTO_FIELD_INFO(deleteById) {
		info->description = ZH_WORDS_GETTER("archives.newField.deleteById");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif