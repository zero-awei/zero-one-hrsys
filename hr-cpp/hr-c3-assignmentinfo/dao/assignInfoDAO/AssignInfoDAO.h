#pragma once
#ifndef _ASSIGN_INFO_DAO_
#define _ASSIGN_INFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/assignInfoDO/AssignInfoDO.h"
#include "../../domain/query/assignInfo/AssignInfoQuery.h"

/**
 * 示例表数据库操作实现
 */
class AssignInfoDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const AssignInfoQuery::Wrapper& query);
	// 分页查询数据
	list<AssignInfoDO> selectWithPage(const AssignInfoQuery::Wrapper& query);
	// 通过id查询数据
	list<AssignInfoDO> selectById(const string& id);
	// 插入数据
	uint64_t insert(const AssignInfoDO& iObj);
	// 修改数据
	int update(const AssignInfoDO& uObj);
	// 通过ID删除数据
	int deleteById(string id);
};
#endif // !_ASSIGN_INFO_DAO_
