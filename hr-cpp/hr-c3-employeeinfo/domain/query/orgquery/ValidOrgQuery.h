#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ValidOrgQuery : public PageQuery {
    DTO_INIT(ValidOrgQuery, PageQuery);

    // ËÑË÷Æ¥Åä
    DTO_FILED(String, filter)
    DTO_FILED_INFO(filter) {
        info->description = ZH_WORDS_GETTER("validorg.query.filter");
    }
    // ¸¸×éÖ¯id
    DTO_FILED(String, porgid);
    DTO_FILED_INFO(porgid) {
        info->description = ZH_WORDS_GETTER("validorg.query.porgid");
    }
    // ÅÅÐò·½Ê½
    DTO_FILED(String, sort);
    DTO_FILED_INFO(sort) {
        info->description = ZH_WORDS_GETTER("validorg.query.sort");
    }
};

#include OATPP_CODEGEN_END(DTO)