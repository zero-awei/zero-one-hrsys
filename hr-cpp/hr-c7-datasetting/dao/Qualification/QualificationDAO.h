#pragma once
#ifndef _QUALIFICATION_DAO_H_
#define _QUALIFICATION_DAO_H_

#include "BaseDAO.h"
#include "../../domain/do/Qualification/QualificationDO.h"
#include "../../domain/query/Qualification/QualificationQuery.h"

/**
 * 示例表数据库操作实现
 */
class QualificationDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const QualificationQuery::Wrapper& query);
	// 分页查询数据
	std::list<QualificationDO> selectWithPage(const QualificationQuery::Wrapper& query);
	// 通过姓名查询数据
	list<QualificationDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const QualificationDO& iObj);
	// 修改数据
	int update(const QualificationDO& uObj);
	// 通过ID删除数据
	int deleteById(const std::string& id);
};
#endif // !_QUALIFICATION_DAO_
