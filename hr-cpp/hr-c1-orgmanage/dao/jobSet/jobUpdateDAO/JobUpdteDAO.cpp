#include "stdafx.h"
#include "JobUpdteDAO.h"

bool JobUpdteDAO::updateJob(const PostDetailDO& data)
{
	sqlSession->beginTransaction();

	stringstream sql;
	sql << "UPDATE `t_ormpost` SET `ORMPOSTNAME`=?, `ISKEYPOSTION`=?, `CREATEMAN`=?, ";
	sql << "`UPDATEMAN`=?, `CREATEDATE`=?, `UPDATEDATE`=?, `ORMORGID`=?, `GWTYPE`=?, `GWFL`=?, `ISCONFIDENTIAL`=?, ";
	sql << "`ISTEMP`=?, `POSTNATURE`=?, `STARTSTOPSIGN`=?";
	sql << "WHERE ORMPOSTID = ";
	sql << data.getOrmPostId();

	string mysql = sql.str();
	
	return sqlSession->executeUpdate(mysql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		data.getOrmPostName(), data.getIsKeyPostion(), data.getCreateMan(),
		data.getUpdateMan(), data.getCreateDate(), data.getUpdateDate(), data.getOrmOrgId(),
		data.getGwType(), data.getGwfl(), data.getIsConfidential(), data.getIsTemp(),
		data.getPostNature(), data.getStartStopSign());
}
