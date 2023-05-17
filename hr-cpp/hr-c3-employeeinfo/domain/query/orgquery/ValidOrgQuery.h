#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ValidOrgQuery : public PageQuery {
    DTO_INIT(ValidOrgQuery, PageQuery);

    // 搜索匹配
    DTO_FILED(String, filter)
    DTO_FILED_INFO(filter) {
        info->description = ZH_WORDS_GETTER("validorg.query.filter");
    }
    // 父组织id
    DTO_FILED(String, porgid);
    DTO_FILED_INFO(porgid) {
        info->description = ZH_WORDS_GETTER("validorg.query.porgid");
    }
    // 页码
    DTO_FILED(UInt64, page);
    DTO_FILED_INFO(page) {
        info->description = ZH_WORDS_GETTER("validorg.query.page");
    }
    // 一页的记录数
    DTO_FILED(UInt64, size);
    DTO_FILED_INFO(size) {
        info->description = ZH_WORDS_GETTER("validorg.query.size");
    }
    // 排序方式
    DTO_FILED(String, sort);
    DTO_FILED_INFO(sort) {
        info->description = ZH_WORDS_GETTER("validorg.query.sort");
    }
};

#include OATPP_CODEGEN_END(DTO)