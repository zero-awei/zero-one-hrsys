#pragma once
#ifndef _CONTRACT_CATEGORY_DAO_H_
#define _CONTRACT_CATEGORY_DAO_H_

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
	std::list<ContractCategoryDO> selectWithPage(const ContractCategoryQuery::Wrapper& query);
	// 根据Id查询数据
	ContractCategoryDO selectById(const std::string& id);
	// 插入新的合同类型
	uint64_t insert(const ContractCategoryDO& data);
	// 更新特定合同类型
	int update(const ContractCategoryDO& data);
	// 删除特定合同类型
	int deleteById(const std::string& id);
};

#endif // _CONTRACT_CATEGORY_DAO_H_
