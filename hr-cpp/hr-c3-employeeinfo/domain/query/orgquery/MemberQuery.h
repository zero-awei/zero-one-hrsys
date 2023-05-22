#pragma once

#ifndef _MEMBER_QUERY_
#define _MEMBER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MemberQuery : public PageQuery {
    DTO_INIT(MemberQuery, PageQuery);

    // 查询Member的parent是OrmOrg还是OrmOrgsector
	DTO_FIELD(String, parentdename);
	DTO_FIELD_INFO(parentdename) {
		info->description = ZH_WORDS_GETTER("member.query.parentdename");
	}
    // 查询的parent id
	DTO_FIELD(String, parentkey);
	DTO_FIELD_INFO(parentkey) {
		info->description = ZH_WORDS_GETTER("member.query.parentkey");
	}
    // 页码
	DTO_FIELD(UInt64, page);
	DTO_FIELD_INFO(page) {
		info->description = ZH_WORDS_GETTER("member.query.page");
	}
    // 一页的记录数
	DTO_FIELD(UInt64, size);
	DTO_FIELD_INFO(size) {
		info->description = ZH_WORDS_GETTER("member.query.size");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MEMBER_QUERY_