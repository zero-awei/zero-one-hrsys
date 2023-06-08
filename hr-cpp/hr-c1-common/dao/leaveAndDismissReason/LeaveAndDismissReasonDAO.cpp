
#include "stdafx.h"
#include "LeaveAndDismissReasonDAO.h"
#include "LeaveAndDismissReasonMapper.h"
#include "domain/do/leaveAndDismissReason/LeaveAndDismissReasonDO.h"
std::list<LeaveAndDismissReasonDO> LeaveAndDismissReasonDAO::selectReasonList()
{
	string sql = "SELECT DISTINCT PCMREASONNAME, PX FROM t_pcmreason";
	LeaveAndDismissReasonMapper mapper;
	return sqlSession->executeQuery<LeaveAndDismissReasonDO, LeaveAndDismissReasonMapper>(sql, mapper);
}
