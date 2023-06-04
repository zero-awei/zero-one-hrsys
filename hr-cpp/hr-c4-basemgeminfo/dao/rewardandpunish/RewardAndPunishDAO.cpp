 #include "stdafx.h"
#include "RewardAndPunishDAO.h"
#include "RewardAndPunishMapper.h"

//查看指定
list<RewardAndPunishDO> RewardAndPunishDAO::selectDetail(const RewardAndPunishDetailQuery::Wrapper& query)
{
	stringstream sql;
	sql << " SELECT PIMREWARDPUNISHMENTID,LX,PIMREWARDPUNISHMENTNAME,JCJB,JCJE,JLSJ,DEPARTMENT,JCSJ,BZ,FJ FROM `t_pimrewardpunishment` WHERE `PIMREWARDPUNISHMENTID`=? ";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->pimrewardpunishmentid.getValue(""));
	RewardAndPunishMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RewardAndPunishDO, RewardAndPunishMapper>(sqlStr, mapper, params);
}

//修改
//有问题，不知道怎么改
int RewardAndPunishDAO::update(const RewardAndPunishDO& uObj)
{
	string sql = " UPDATE `t_pimrewardpunishment` SET `CREATEDATE`=?, `UPDATEDATE`=?, `PIMREWARDPUNISHMENTNAME`=?, `UPDATEMAN`=?, `CREATEMAN`=?, `ENABLE`=?, `FJ`=?, `LX`=?, `CSRQ`=?, `PIMPERSONID`=?, `JCJB`=?, `JCLX`=?, `JLSJ`=?, `CFSJ`=?, `JCJE`=?, `JCSJ`=?, `BZ`=?, `CFLX`=?, `JLSS`=?, `JLGLBH`=?, `JLSPZT`=?, `JLCZZ`=?, `YXQJSRQ`=?, `DEPARTMENT`=?, `REASON`=? WHERE `PIMREWARDPUNISHMENTID`=? ";
	
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", uObj.get_CREATEDATE(),uObj.get_UPDATEDATE(),uObj.get_PIMREWARDPUNISHMENTNAME(),uObj.get_UPDATEMAN(),uObj.get_CREATEMAN(),uObj.get_ENABLE(),uObj.get_FJ(),uObj.get_LX(),uObj.get_CSRQ(),uObj.get_PIMPERSONID(),uObj.get_JCJB(),uObj.get_JCLX(),uObj.get_JLSJ(),uObj.get_CFSJ(),uObj.get_JCJE(),uObj.get_JCSJ(),uObj.get_BZ(),uObj.get_CFLX(),uObj.get_JLSS(),uObj.get_JLGLBH(),uObj.get_JLSPZT(),uObj.get_JLCZZ(),uObj.get_YXQJSRQ(),uObj.get_DEPARTMENT(),uObj.get_REASON(),uObj.get_PIMREWARDPUNISHMENTID());
}

//分页查询
list<RewardAndPunishDO> RewardAndPunishDAO::selectWithPage(const RewardAndPunishDownloadQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM `t_pimrewardpunishment` WHERE `PIMPERSONID`=? LIMIT 5000";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue(""));
	RewardAndPunishMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RewardAndPunishDO, RewardAndPunishMapper>(sqlStr, mapper, params);
}