#pragma once
/*
人员花名册-离退休人员-分页查询员工列表--pine
*/
#ifndef _CHECH_RETIRES_LIST_DAO_
#define _CHECH_RETIRES_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/RetiredEmployeesDO.h"
#include "../../domain/query/RosterOfPer/CheckRetiresListQuery.h"

class CheckRetiresListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CheckRetiresListQuery::Wrapper& query);
	// 分页查询数据
	list<RetiredEmployeesDO> selectWithPage(const CheckRetiresListQuery::Wrapper& query);

};
#endif // !_CHECH_RETIRES_LIST_DAO_
