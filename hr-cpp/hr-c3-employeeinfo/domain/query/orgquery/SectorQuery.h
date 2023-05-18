#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SectorQuery : public PageQuery {
    DTO_INIT(SectorQuery, PageQuery);

    // 查询Sector的parent是OrmOrg还是OrmOrgsector
    DTO_FILED(String, parentdename)
    DTO_FILED_INFO(parentdename) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.parentdename");
    }
    // 查询的parent id
    DTO_FILED(String, parentkey)
    DTO_FILED_INFO(parentkey) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.parentkey");
    }
    // 排序方式
    DTO_FILED(String, sort);
    DTO_FILED_INFO(sort) {
        info->description = ZH_WORDS_GETTER("sectorquery.query.sort");
    }
};

#include OATPP_CODEGEN_END(DTO)