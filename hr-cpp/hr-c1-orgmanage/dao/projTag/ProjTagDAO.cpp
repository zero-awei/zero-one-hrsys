
#include "stdafx.h"
#include "ProjTagDAO.h"

uint64_t ProjTagDAO::insert(const ProjTagDO& iObj)
{
	// ORMXMBQID CREATEMAN ORMXMBQNAME UPDATEMAN CREATEDATE UPDATEDATE ORMORGID
	string sql = "INSERT INTO `t_ormxmbq` \
				(`ORMXMBQID`, `CREATEMAN`, `ORMXMBQNAME`, `UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`, `ORMORGID`)\
				 VALUES (?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s", \
				iObj.getId(), iObj.getCreator(), iObj.getTagName(), \
				iObj.getUpdater(), iObj.getCreateTime(), iObj.getUpdateTime(), iObj.getOrgId());
}
