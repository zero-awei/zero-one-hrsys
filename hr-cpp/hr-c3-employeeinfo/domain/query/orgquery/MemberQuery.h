#pragma once

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class MemberQuery : public PageQuery {
    DTO_INIT(MemberQuery, PageQuery);

    // 查询Member的parent是OrmOrg还是OrmOrgsector
    DTO_FILED(String, parentdename)
    DTO_FILED_INFO(parentdename) {
        info->description = ZH_WORDS_GETTER("member.query.parentdename");
    }
    // 查询的parent id
    DTO_FILED(String, parentkey);
    DTO_FILED_INFO(parentkey) {
        info->description = ZH_WORDS_GETTER("member.query.parentkey");
    }
    // 页码
    DTO_FILED(UInt64, page);
    DTO_FILED_INFO(page) {
        info->description = ZH_WORDS_GETTER("member.query.page");
    }
    // 一页的记录数
    DTO_FILED(UInt64, size);
    DTO_FILED_INFO(size) {
        info->description = ZH_WORDS_GETTER("member.query.size");
    }
};

#include OATPP_CODEGEN_END(DTO)