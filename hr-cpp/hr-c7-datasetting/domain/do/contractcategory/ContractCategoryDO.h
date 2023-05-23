#pragma once
#ifndef _CONTRACT_CATEGORY_DO_
#define _CONTRACT_CATEGORY_DO_
#include "../DoInclude.h"

/**
 * 合同类型数据库实体类
 */
class ContractCategoryDO
{
    // 编号
    CC_SYNTHESIZE(uint64_t, id, Id);
    // 类型名称
    CC_SYNTHESIZE(string, name, Name);
    // 类型描述
    CC_SYNTHESIZE(string, description, Description);
public:
    ContractCategoryDO() {
        id = 0;
        name = "";
        description = "";
    }
};

#endif // !_
