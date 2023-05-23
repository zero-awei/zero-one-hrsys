#pragma once

#ifndef _VALID_ORG_QUERY_
#define _VALID_ORG_QUERY_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ValidOrgQuery : public PageQuery {
    DTO_INIT(ValidOrgQuery, PageQuery);

    // ËÑË÷Æ¥Åä
    API_DTO_FIELD_DEFAULT(String, fillter, ZH_WORDS_GETTER("validorg.query.filter"));
    // ¸¸×éÖ¯id
    API_DTO_FIELD_DEFAULT(String, porgid, ZH_WORDS_GETTER("validorg.query.porgid"));
    // ÅÅÐò·½Ê½
	DTO_FIELD(String, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("validorg.query.sort");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_VALID_ORG_QUERY_