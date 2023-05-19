#include "stdafx.h"
#include "ArchivesDAO.h"
#include "ArchivesMapper.h"

//定义条件解析宏，减少重复代码
#define CONTRACT_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `PIMPERSONNAME`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
}

uint64_t ArchivesDAO::count(const ArchivesQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM `t_pimarchives` a INNER JOIN `t_pimperson` b ON a.PIMPERSONID=b.PIMPERSONID ";
	CONTRACT_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ArchivesDO> ArchivesDAO::selectWithPage(const ArchivesQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT YGBH,PIMPERSONNAME,DABH,ORMORGID3,DABGD,ARCHIVESCENTERID,EDUCATION,DATEOFBIRTH,JOINPARTYDATE,STARTWORKDATAE,DAZT FROM `t_pimarchives` as a, `t_pimperson` as b where a.PIMPERSONID=b.PIMPERSONID";
	CONTRACT_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ArchivesMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ArchivesDO, ArchivesMapper>(sqlStr, mapper, params);
}