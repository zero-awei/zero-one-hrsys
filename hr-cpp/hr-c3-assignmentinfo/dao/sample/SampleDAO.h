#pragma once
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/sample/SampleDO.h"
#include "../../domain/query/assignInfo/AssignInfoQuery.h"

/**
 * 示例表数据库操作实现
 */
class SampleDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const AssignInfoQuery::Wrapper& query);
	// 分页查询数据
	list<SampleDO> selectWithPage(const AssignInfoQuery::Wrapper& query);
	// 通过姓名查询数据
	list<SampleDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const SampleDO& iObj);
	// 修改数据
	int update(const SampleDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
