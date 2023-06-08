#include "stdafx.h"
#include "ArchivesDAO.h"
#include "ArchivesMapper.h"

//定义条件解析宏，减少重复代码
#define CONTRACT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimpersonid) { \
	sql << " AND `PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
}

//定义条件解析宏，减少重复代码
#define CONTRACT_TERAM_PARSE2(query, sql) \
SqlParams params; \
if (query->pimpersonid) { \
	sql << " AND `PIMPERSONID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
}


uint64_t ArchivesDAO::count(const ArchivesQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimarchives";
	CONTRACT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ArchivesDO> ArchivesDAO::selectWithPage(const ArchivesQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT DABH,ORMORGID3,DABGD,ARCHIVESCENTERNAME,EDUCATION,DATEOFBIRTH,JOINPARTYDATE,STARTWORKDATAE,DAZT FROM `t_pimarchives` a,`t_archivescenter` b WHERE  a.ARCHIVESCENTERID=b.ARCHIVESCENTERID";
	//sql << "SELECT DABH,ORMORGID3,DABGD,ARCHIVESCENTERID,EDUCATION,DATEOFBIRTH,JOINPARTYDATE,STARTWORKDATAE,DAZT FROM `t_pimarchives` ";
	//sql << "SELECT * FROM t_pimarchives";
	CONTRACT_TERAM_PARSE2(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ArchivesMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ArchivesDO, ArchivesMapper>(sqlStr, mapper, params);
}