
#include "stdafx.h"
#include "DismissReasonDAO.h"
#include "domain/do/dismissReason/DismissReasonDO.h"
#include "dao/dismissReason/DismissReasonMapper.h"

std::list<DismissReasonDO> DismissReasonDAO::queryDismissReasonList()
{
	string sql = "SELECT DISTINCT PCMREASONNAME FROM t_pcmreason";
	DismissReasonMapper mapper;
	return sqlSession->executeQuery<DismissReasonDO, DismissReasonMapper>(sql, mapper);
}
