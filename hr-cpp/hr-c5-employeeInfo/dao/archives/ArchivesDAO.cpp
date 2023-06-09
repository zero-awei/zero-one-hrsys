#include "stdafx.h"
#include "ArchivesDAO.h"
#include "ArchivesMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
// asd
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimArchivesId) { \
	sql << " AND PIMARCHIVESID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimArchivesId.getValue("")); \
} \
if (query->pimPersonName) { \
	sql << " AND PIMPERSONNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimPersonName.getValue("")); \
} \
if (query->ygbh) { \
	sql << " AND YGBH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ygbh.getValue("")); \
} \
if (query->dabh) { \
	sql << " AND DABH=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->dabh.getValue("")); \
} \
if (query->ygzt) { \
	sql << " AND YGZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ygzt.getValue("")); \
} \
if (query->dazt) { \
	sql << " AND DAZT=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->dazt.getValue("")); \
} 

list<t_pimarchivesDO> ArchivesDAO::selectAll(const ArchivesQuery::Wrapper & query) {
	stringstream sql;
	sql << "SELECT \
		tpa.PIMARCHIVESID, \
		tpa.DABH, \
		tso.ORGNAME, \
		tpa.DABGD, \
		tas.ARCHIVESCENTERNAME, \
		tpa.DAZT, \
		tpp.YGBH, \
		tpp.PIMPERSONNAME, \
		tpp.YGZT, \
		tpa.ORMORGNAME, \
		tpa.ZT, \
		tpa.EDUCATION, \
		tpa.DATEOFBIRTH, \
		tpa.JOINPARTYDATE, \
		tpa.STARTWORKDATAE \
		FROM \
		`t_pimarchives` AS tpa \
		INNER JOIN `t_pimperson` AS tpp ON tpa.PIMPERSONID=tpp.PIMPERSONID \
		INNER JOIN `t_srforg` AS tso ON tpa.ORMORGID3=tso.ORGID \
		INNER JOIN `t_archivescenter` AS tas ON tpa.ARCHIVESCENTERID=tas.ARCHIVESCENTERID";
	SAMPLE_TERAM_PARSE(query, sql);

	//sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ArchivesMapperDetail mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<t_pimarchivesDO, ArchivesMapperDetail>(sqlStr, mapper, params);
}

uint64_t ArchivesDAO::count(const ArchivesQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_pimarchives` AS tpa \
		INNER JOIN `t_pimperson` AS tpp ON tpa.PIMPERSONID = tpp.PIMPERSONID \
		INNER JOIN `t_srforg` AS tso ON tpa.ORMORGID3 = tso.ORGID \
		INNER JOIN `t_archivescenter` AS tas ON tpa.ARCHIVESCENTERID = tas.ARCHIVESCENTERID";
	SAMPLE_TERAM_PARSE(query, sql);

	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<t_pimarchivesDO> ArchivesDAO::selectWithPage(const ArchivesQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT \
		tpa.PIMARCHIVESID, \
		tpa.DABH, \
		tso.ORGNAME, \
		tpa.DABGD, \
		tas.ARCHIVESCENTERNAME, \
		tpa.DAZT, \
		tpp.YGBH, \
		tpp.PIMPERSONNAME, \
		tpp.YGZT, \
		tpa.ORMORGNAME, \
		tpa.ZT \
		FROM \
		`t_pimarchives` AS tpa \
		INNER JOIN `t_pimperson` AS tpp ON tpa.PIMPERSONID=tpp.PIMPERSONID \
		INNER JOIN `t_srforg` AS tso ON tpa.ORMORGID3=tso.ORGID \
		INNER JOIN `t_archivescenter` AS tas ON tpa.ARCHIVESCENTERID=tas.ARCHIVESCENTERID";
	SAMPLE_TERAM_PARSE(query, sql);

	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ArchivesMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<t_pimarchivesDO, ArchivesMapper>(sqlStr, mapper, params);
}

uint64_t ArchivesDAO::insert(const t_pimarchivesDO& iObj, uint64_t id)
{
	std::string sql = "	INSERT INTO `t_pimarchives` ( `PIMARCHIVESID`, `DABH`, `DABGD`, `DAZT`, `ZT`,  \
		`EDUCATION`, `DATEOFBIRTH`, `JOINPARTYDATE`,`STARTWORKDATAE`, \
		`PIMPERSONID`, ORMORGID3, ARCHIVESCENTERID ) \
		VALUES(?, ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? ) ";

	//事务
	SqlSession sqlsession;
	//开启事务
	sqlsession.beginTransaction();

	int row = sqlSession->executeUpdate(sql, "%s%s%s%s%s %s%s%s%s %s%s%s", 
		std::to_string(id), iObj.getDabh(), iObj.getDabgd(), iObj.getDazt(), iObj.getZt(),
		iObj.getEducation(), iObj.getDateOfBirth(), iObj.getJoinPartyDate(), iObj.getStartWorkDatae(),
		iObj.getPimPersonId(), iObj.getOrMorGId3(), iObj.getArchivesCenterId());
	//判断插入是否成功
	if (row == 1) sqlsession.commitTransaction();
	else sqlsession.rollbackTransaction();
	return row;
}

int ArchivesDAO::deleteById(const string& pimArchivesid)
{
	SqlSession sqlsession;
	sqlsession.beginTransaction();

	string sql = "SET FOREIGN_KEY_CHECKS = 0";
	sqlSession->executeUpdate(sql);
	sql = "DELETE FROM `t_pimarchives` WHERE `PIMARCHIVESID`=?";
	int row = sqlSession->executeUpdate(sql, "%s", pimArchivesid);
	sql = "SET FOREIGN_KEY_CHECKS = 1;";
	sqlSession->executeUpdate(sql);

	if (row == 1) sqlsession.commitTransaction();
	else sqlsession.rollbackTransaction();
	return row;
}

