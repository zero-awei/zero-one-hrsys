#pragma once
#ifndef _Gosh_DAO_
#define _Gosh_DAO_
#include "BaseDAO.h"
#include "domain/do/Gosh/ContractDO.h"
#include "domain/query/Gosh/ContractQuery.h"

/**
 * 示例表数据库操作实现
 */
class GoshDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ContractQuery::Wrapper& query);
	// 分页查询数据
	list<ContractDO> selectWithPage(const ContractQuery::Wrapper& query);
	// 通过姓名查询数据
	list<ContractDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const ContractDO& iObj);
	// 通过ID删除数据
	int deleteById(std::string id);
};
#endif // !_SAMPLE_DAO_