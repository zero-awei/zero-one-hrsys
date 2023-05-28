#include "stdafx.h"
#include "RewardAndPunishDAO.h"
#include "RewardAndPunishMapper.h"

list<RewardAndPunishDO> RewardAndPunishDAO::selectDetail(const RewardAndPunishViewQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimarmycadres` WHERE `PIMARMYCADRESID`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMREWARDPUNISHMENTID.getValue(""));
	RewardAndPunishMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RewardAndPunishDO, RewardAndPunishMapper>(sqlStr, mapper, params);
}

int RewardAndPunishDAO::update(const RewardAndPunishDO& uObj)
{
	string sql = "UPDATE `t_pimarmycadres` SET `CREATEDATE`=?, `UPDATEDATE`=?, `PIMREWARDPUNISHMENTNAME`=? ,`UPDATEMAN`=? ,`CREATEMAN`=? ,`FJ`=? ,`LX`=? ,`CSRQ`=? ,`PIMREWARDPUNISHMENTID`=? ,`PIMPERSONID`=? ,`JCJB`=? ,`JCLX`=? ,`JLSJ`=? ,`CFSJ`=? ,`JCJE`=? ,`JCSJ`=? ,`BZ`=? ,`CFLX`=? ,`JLSS`=? ,`JLGLBH`=? ,`JLSPZT`=? ,`JLCCZZ`=? ,`YXQJSRQ`=? ,`DEPARTMENT`=? ,`REASON`=? WHERE `PIMARMYCADRESID`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", uObj.get_CREATEDATE(), uObj.get_UPDATEDATE(), uObj.get_PIMREWARDPUNISHMENTNAME(), uObj.get_UPDATEMAN(), uObj.get_CREATEMAN(), uObj.get_FJ(), uObj.get_LX(), uObj.get_CSRQ(), uObj.get_PIMREWARDPUNISHMENTID(), uObj.get_PIMPERSONID(), uObj.get_JCJB(), uObj.get_JCLX(), uObj.get_JLSJ(), uObj.get_CFSJ(), uObj.get_JCJE(), uObj.get_JCSJ(), uObj.get_BZ(), uObj.get_CFLX(), uObj.get_JLSS(), uObj.get_JLGLBH(), uObj.get_JLSPZT(), uObj.get_JLCZZ(), uObj.get_YXQJSRQ(), uObj.get_DEPARTMENT(), uObj.get_REASON());
}

list<RewardAndPunishDO> RewardAndPunishDAO::selectWithPage(const RewardAndPunishDownloadQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimarmycadres` WHERE `PIMPERSONID`=? LIMIT 5000";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->PIMPERSONID.getValue(""));
	RewardAndPunishMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RewardAndPunishDO, RewardAndPunishMapper>(sqlStr, mapper, params);
}
