#pragma once

#ifndef _T_PIMPATENT_DAO_
#define _T_PIMPATENT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/patentinfo/t_pimpatentDO.h"
#include "../../domain/query/patentinfo/PatentinfoQuery.h"

/**
 * 专利信息表数据库操作实现
 */
class t_pimpatentDAO : public BaseDAO
{
public:
	// 添加指定员工的专利信息
	uint64_t insert(const PatentinfoDO& iObj, string idStr, string datetime);
	// 统计数据条数
	uint64_t count(const PatentinfoQuery::Wrapper& query);
	// 分页查询数据
	list<PatentinfoDO> selectWithPage(const PatentinfoQuery::Wrapper& query);

	// 通过员工编号删除数据
	int deleteById(string pimpaperid);
	// 通过DTO查询数据ID
	uint64_t selectpatentID(const PatentinfoDO& sdo);
};
#endif
