#pragma once
#ifndef _LOANEDPER_DAO_
#define _LOANEDPER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/RosterOfPer/SecondedPersonnelDO.h"
#include "../../domain/query/RosterOfPer/LoanedPerPageQuery.h"

/**
 * 借调人员数据库操作实现--(人员花名册-借调人员-分页查询员工列表)--luoluo
 */
class LoanedPerDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const LoanedPerPageQuery::Wrapper& query);
	// 分页查询数据
	list<SecondedPersonnelDO> selectWithPage(const LoanedPerPageQuery::Wrapper& query);
	// 导出查询
	list<SecondedPersonnelDO> selectExportDatas(const LoanedPerPageQuery::Wrapper& query);
};
#endif // !_LOANEDPER_DAO_