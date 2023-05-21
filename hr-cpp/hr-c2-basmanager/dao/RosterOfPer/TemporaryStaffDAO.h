#pragma once
#ifndef _TEMPORARYSTAFF_DAO_
#define _TEMPORARYSTAFF_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/TemporaryStaffDO.h"
#include "../../domain/query/RosterOfPer/TemporaryStaffQuery.h"

/**
 * 挂职人员数据库操作实现
 */
class TemporaryStaffDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const TempStaffQuery::Wrapper& query);
	// 分页查询数据
	list<TemporaryStaffDO> selectWithPage(const TempStaffQuery::Wrapper& query);
	// 通过姓名查询数据
	list<TemporaryStaffDO> selectByName(const string& name);
};
#endif // !_TEMPORARYSTAFF_DAO_