#include "stdafx.h"
#include "RewardAndPunishmentInformationDAO.h"
#include "RewardAndPunishmentInformationMapper.h"
#include "domain/do/rewardandpunishmentinformation/RewardAndPunishmentInformationDO.h"

//定义条件解析宏，减少重复代码
#define REWARDANDPUNISHMENTINFORMATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimpersonid) { \
	sql << " AND `PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
}


uint64_t RewardAndPunishmentInformationDAO::count(const RewardAndPunishmentInformationPageQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_pimrewardpunishment`";
	REWARDANDPUNISHMENTINFORMATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}


list<RewardAndPunishmentInformationDO> RewardAndPunishmentInformationDAO::selectWithPage(const RewardAndPunishmentInformationPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT LX,PIMREWARDPUNISHMENTNAME,JCJB,JCJE,JLSJ,JCSJ,BZ,FJ FROM `t_pimrewardpunishment`";
	REWARDANDPUNISHMENTINFORMATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	RewardAndPunishmentInformationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<RewardAndPunishmentInformationDO, RewardAndPunishmentInformationMapper>(sqlStr, mapper, params);
}

int RewardAndPunishmentInformationDAO::insert(const RewardAndPunishmentInformationDO& iObj)
{
	string sql = "INSERT INTO `t_pimrewardpunishment` (`PIMREWARDPUNISHMENTNAME`, `LX`, `JCJB`,`JCJE`,`JLSJ`,`JCSJ`,`BZ`,`FJ`,`PIMREWARDPUNISHMENTID`,`UPDATEDATE`,`CREATEDATE`,`CREATEMAN`,`UPDATEMAN`,`PIMPERSONID`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%d%s%s%s%s%s%s%s%s%s%s", iObj.getPimrewardpunishmentname(), iObj.getLx(), iObj.getJcjb(), iObj.getJcje(), iObj.getJlsj(), iObj.getJcsj(), iObj.getBz(), iObj.getFj(), iObj.getPimrewardpunishmentid(), iObj.getUpdatedate(), iObj.getCreatedate(), iObj.getCreateman(), iObj.getUpdateman(),iObj.getPimpersonid());
}



int  RewardAndPunishmentInformationDAO::deleteById(std::string pimpersonid, std::string pimrewardpunishmentid)
{
	std::string sql = "delete from t_pimrewardpunishment where PIMPERSONID=? and PIMREWARDPUNISHMENTID=?";
	return sqlSession->executeUpdate(sql, "%s%s", pimpersonid, pimrewardpunishmentid);
}