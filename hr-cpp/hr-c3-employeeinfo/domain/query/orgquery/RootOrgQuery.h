#pragma once

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
    // Ò³Âë
    DTO_FILED(UInt64, page);
    DTO_FILED_INFO(page) {
        info->description = ZH_WORDS_GETTER("rootorg.query.page");
    }
    // Ò»Ò³µÄ¼ÇÂ¼Êý
    DTO_FILED(UInt64, size);
    DTO_FILED_INFO(size) {
        info->description = ZH_WORDS_GETTER("rootorg.query.size");
    }
    // ÅÅÐò·½Ê½
    DTO_FILED(String, sort);
    DTO_FILED_INFO(sort) {
        info->description = ZH_WORDS_GETTER("rootorg.query.sort");
    }
};

#include OATPP_CODEGEN_END(DTO)