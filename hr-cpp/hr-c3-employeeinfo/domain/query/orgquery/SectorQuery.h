#pragma once

#ifndef _SECTOR_QUERY_
#define _SECTOR_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SectorQuery : public PageQuery {
    DTO_INIT(SectorQuery, PageQuery);

    // 查询Sector的parent是OrmOrg还是OrmOrgsector
    API_DTO_FIELD_DEFAULT(String, parentdename, ZH_WORDS_GETTER("sector.query.parentdename"));
    // 查询的parent id
    API_DTO_FIELD_DEFAULT(String, parentkey, ZH_WORDS_GETTER("sector.query.parentkey"));
    // 排序方式
    DTO_FIELD(String, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("sector.query.sort");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SECTOR_QUERY_
