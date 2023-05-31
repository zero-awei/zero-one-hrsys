#include "stdafx.h"
#include "JobUpdteDAO.h"

bool JobUpdteDAO::updateJob(const PostDetailDO& data)
{
	stringstream sql;
	sql << "UPDATE `t_ormpost` SET `ORMPOSTNAME`=?, `ISKEYPOSTION`=?, ";
	sql << "`ORMORGID`=?, `GWTYPE`=?, `GWFL`=?, `ISCONFIDENTIAL`=?, ";
	sql << "`ISTEMP`=?, `POSTNATURE`=?, `STARTSTOPSIGN`=? , `UPDATEDATE`=?, `UPDATEMAN`=? ";
	sql << "WHERE `ORMPOSTID`=?";
	//sql << "UPDATE `t_ormpost` SET `ORMPOSTNAME` = `" + data.getOrmPostName()+"`";
	//sql << "WHERE `ORMPOSTID` = `091EB600-927F-4CDF-9006-76D710592542`";

	string mysql = sql.str();
	
	//return sqlSession->executeUpdate(mysql)!=0;
	return sqlSession->executeUpdate(mysql, "%s%s%s%s%s%s%s%s%s%s%s%s",
		data.getOrmPostName(), data.getIsKeyPostion(), data.getCreateMan(),
		data.getCreateDate(), data.getOrmOrgId(),data.getGwType(), 
		data.getGwfl(), data.getIsConfidential(), data.getIsTemp(),
		data.getPostNature(), data.getStartStopSign(), data.getOrmPostId(), data.getUpdateDate(), data.getUpdateMan());
}
