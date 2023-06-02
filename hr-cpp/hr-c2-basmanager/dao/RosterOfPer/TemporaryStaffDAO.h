#pragma once
#ifndef _TEMPORARYSTAFF_DAO_
#define _TEMPORARYSTAFF_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/TemporaryStaffDO.h"
#include "../../domain/query/RosterOfPer/TemporaryStaffQuery.h"

/**
 * 挂职人员数据库操作实现--(人员花名册-挂职人员-分页查询员工列表)--weixiaoman
 */
class TemporaryStaffDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const TempStaffQuery::Wrapper& query);
	// 分页查询数据
	list<TemporaryStaffDO> selectWithPage(const TempStaffQuery::Wrapper& query);
	// 导出查询数据
	list<TemporaryStaffDO> selectExportDatas(const TempStaffQuery::Wrapper& query);
};
#endif // !_TEMPORARYSTAFF_DAO_