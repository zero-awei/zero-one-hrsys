#pragma once

#ifndef _ROOT_ORG_QUERY_
#define _ROOT_ORG_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

class RootOrgQuery : public PageQuery {
    DTO_INIT(RootOrgQuery, PageQuery);

    // ËÑË÷Æ¥Åä
    DTO_FILED(String, filter)
    DTO_FILED_INFO(filter) {
        info->description = ZH_WORDS_GETTER("rootorg.query.filter");
    }
    // ÅÅÐò·½Ê½
	DTO_FIELD(String, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("rootorg.query.sort");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ROOT_ORG_QUERY_