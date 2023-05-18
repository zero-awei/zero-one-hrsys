#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SectorQuery : public PageQuery {
    DTO_INIT(SectorQuery, PageQuery);

    // 查询的parent id
    DTO_FILED(String, parentkey)
    DTO_FILED_INFO(parentkey) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.parentkey");
    }
    // 页码
    DTO_FILED(UInt64, page);
    DTO_FILED_INFO(page) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.page");
    }
    // 一页的记录数
    DTO_FILED(UInt64, size);
    DTO_FILED_INFO(size) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.size");
    }
    // 排序方式
    DTO_FILED(String, sort);
    DTO_FILED_INFO(sort) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.sort");
    }
};

#include OATPP_CODEGEN_END(DTO)