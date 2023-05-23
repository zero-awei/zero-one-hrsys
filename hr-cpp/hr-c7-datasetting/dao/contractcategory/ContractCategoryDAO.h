#pragma once
#ifndef _CONTRACT_CATEGORY_DAO_
#define _CONTRACT_CATEGORY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contractcategory/ContractCategoryDO.h"
#include "../../domain/query/contractcategory/ContractCategoryQuery.h"

/**
 * 合同类型表数据库操作实现
 */
class ContractCategoryDAO : public BaseDAO
{
public:
    // 统计数据条数
    uint64_t count(const ContractCategoryQuery::Wrapper& query);
    // 分页查询数据
    list<ContractCategoryDO> selectWithPage(const ContractCategoryQuery::Wrapper& query);
};
#endif //
