#pragma once

#ifndef _Root_Org_Query_
#define _Root_Org_Query_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

class RootOrgQuery : public PageQuery {
    DTO_INIT(RootOrgQuery, PageQuery);

    // ËÑË÷Æ¥Åä
	DTO_FIELD(String, filter);
	DTO_FIELD_INFO(filter) {
		info->description = ZH_WORDS_GETTER("rootorg.query.filter");
	}
    // Ò³Âë
	DTO_FIELD(UInt32, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("rootorg.query.page");
	}
    // Ò»Ò³µÄ¼ÇÂ¼Êý
	DTO_FIELD(UInt64, size);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("rootorg.query.size");
	}
    // ÅÅÐò·½Ê½
	DTO_FIELD(String, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("rootorg.query.sort");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Root_Org_Query_