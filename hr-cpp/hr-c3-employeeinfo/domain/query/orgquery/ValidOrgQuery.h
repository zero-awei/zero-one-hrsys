#pragma once

#ifndef _VALID_ORG_QUERY_
#define _VALID_ORG_QUERY_


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ValidOrgQuery : public PageQuery {
    DTO_INIT(ValidOrgQuery, PageQuery);

    // 搜索匹配
	DTO_FIELD(String, filter);
	DTO_FIELD_INFO(filter) {
		info->description = ZH_WORDS_GETTER("validorg.query.filter");
	}
    // 父组织id
	DTO_FIELD(String, porgid);
	DTO_FIELD_INFO(porgid) {
		info->description = ZH_WORDS_GETTER("validorg.query.porgid");
	}
    // 页码
	DTO_FIELD(UInt64, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("validorg.query.page");
	}
    // 一页的记录数
	DTO_FIELD(UInt64, size);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("validorg.query.size");
	}
    // 排序方式
	DTO_FIELD(String, sort);
	DTO_FIELD_INFO(sort) {
		info->description = ZH_WORDS_GETTER("validorg.query.sort");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_VALID_ORG_QUERY_