#pragma once

#ifndef _Sector_Query_
#define _Sector_Query_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SectorQuery : public PageQuery {
    DTO_INIT(SectorQuery, PageQuery);

    // 查询的parent id
	DTO_FIELD(String, parentkey);
	DTO_FIELD_INFO(parentkey) {
		info->description = ZH_WORDS_GETTER("sectorquery.query.parentkey");
	}
    // 页码
	DTO_FIELD(UInt64, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("sectorquery.query.page");
	}
    // 一页的记录数
	DTO_FIELD(UInt64, size);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("sectorquery.query.size");
	}
    // 排序方式
	DTO_FIELD(String, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("sectorquery.query.sort");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Sector_Query_
