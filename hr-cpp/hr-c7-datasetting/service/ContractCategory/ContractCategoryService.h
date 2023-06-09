#pragma once               
#ifndef _CONTRACTCATEGORY_SERVICE_
#define _CONTRACTCATEGORY_SERVICE_
#include <list>
#include "domain/vo/contractcategory/ContractCategoryVO.h"
#include "domain/query/contractcategory/ContractCategoryQuery.h"
#include "domain/dto/contractcategory/ContractCategoryDTO.h"

/**
 * 合同类别服务实现
 */
class ContractCategoryService
{
public:
    // 分页查询所有合同类别
    ContractCategoryPageDTO::Wrapper listAll(const ContractCategoryQuery::Wrapper& query);
    // 新建合同类别
    uint64_t addContractCategory(const ContractCategoryDTO::Wrapper& dto);
    // 修改合同类别
    bool modifyContractCategory(const ContractCategoryDTO::Wrapper& dto);
    // 通过ID删除合同类别
    bool removeContractCategory(uint64_t id);
    // 导入合同类别
    // 导出合同类别
};

#endif // !_CONTRACTCATEGORY_SERVICE_

