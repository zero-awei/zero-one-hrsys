
#include "stdafx.h"
#include "LeaveReasonDAO.h"
#include "dao/leaveReason/LeaveReasonMapper.h"
std::list<LeaveReasonDO> LeaveReasonDAO::queryLeaveReasonList()
{
	string sql = "SELECT DISTINCT PCMREASONNAME FROM t_pcmreason";
	LeaveReasonMapper mapper;
	return sqlSession->executeQuery<LeaveReasonDO, LeaveReasonMapper>(sql, mapper);
}
