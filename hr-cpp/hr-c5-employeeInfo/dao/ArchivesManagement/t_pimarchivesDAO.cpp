#include "stdafx.h"
#include "t_pimarchivesDAO.h"
#include "t_pimarchivesMapper.h"
#include <sstream>

#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimpersonid) { \
	sql << " AND `pimpersonid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
}


uint64_t t_pimarchivesDAO::count(const EmployeeNotInArchiveQuery::Wrapper & query) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimarchive";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 分页查询数据
list<t_pimarchivesDO> t_pimarchivesDAO::selectWithPage(const EmployeeNotInArchiveQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT DABH, COALESCE(t_srforg.ORGNAME, '') AS ORGNAME, DABGD, COALESCE(t_archivescenter.ARCHIVESCENTERNAME, '') AS ARCHIVESCENTERNAME, DAZT, t_pimperson.YGBH, t_pimperson.PIMPERSONNAME, COALESCE(t_pimarchives.ORMORGNAME, '') AS ORMORGNAME, t_pimperson.YGZT, OPERATIONS FROM t_pimarchives LEFT JOIN t_srforg ON t_pimarchives.ormorgid3 = t_srforg.ORGID LEFT JOIN t_archivescenter ON t_pimarchives.archivescenterid = t_archivescenter.archivescenterid LEFT JOIN t_pimperson ON t_pimarchives.pimpersonid = t_pimperson.pimpersonid  WHERE  DAZT is NULL AND (YGZT = 20 OR YGZT = 10 OR YGZT = 30)";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	t_pimarchivesMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<t_pimarchivesDO, t_pimarchivesMapper>(sqlStr, mapper, params);
}
// 调入档案  把ygzt从NULL改为"10"
int t_pimarchivesDAO::update(const t_pimarchivesDO& uObj) {
	string sql = "UPDATE `t_pimarchives` SET `ygzt`=10 WHERE `pimpersonid`=?";
	return sqlSession->executeUpdate(sql, "%s",  uObj.getPimpersonid());
};