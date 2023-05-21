#pragma once
#ifndef _NOT_IN_ARCHIVE_QUERY_
#define _NOT_IN_ARCHIVE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class NotInArchiveQuery : public PageQuery {
	DTO_INIT(NotInArchiveQuery, PageQuery);
	//°´ÕÕÐÕÃû²éÑ¯
	DTO_FIELD(String, pimpersonname);
	DTO_FIELD_INFO(pimpersonname) {
		info->description = ZH_WORDS_GETTER("archive.dto.pimpersonname");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_NOT_IN_ARCHIVE_QUERY_