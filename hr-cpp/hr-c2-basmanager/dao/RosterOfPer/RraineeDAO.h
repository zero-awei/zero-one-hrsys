#pragma once
/*

*/
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/RraineeDO.h"
#include "../../domain/query/RosterOfPer/RraineeQuery.h"

/**
 * 示例表数据库操作实现
 */
class RraineeDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const RraineeQuery::Wrapper& query);
	// 分页查询数据
	list<RraineeDO> selectWithPage(const RraineeQuery::Wrapper& query);
	//// 通过姓名查询数据
	//list<RraineeDO> selectByName(const string& name);
	//// 插入数据
	//uint64_t insert(const RraineeDO& iObj);
	//// 修改数据
	//int update(const RraineeDO& uObj);
	//// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
