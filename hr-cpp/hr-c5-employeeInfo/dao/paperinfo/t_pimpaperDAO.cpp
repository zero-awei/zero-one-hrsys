#include "stdafx.h"
#include "t_pimpaperDAO.h"
#include "t_pimpaperMapper.h"
#include <sstream>
#include "SnowFlake.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimpersonid) { \
	sql << " AND `pimpersonid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimpersonid.getValue("")); \
}

int t_pimpaperDAO::insert(const t_pimpaperDO& iObj, string idStr, string datetime)
{
	string sql = "INSERT INTO `t_pimpaper` (`FBSJ`, `CBS`, `KWQS`, `FJ`, `GRZLWZZZDPM`, `KWMC`, `PIMPAPERNAME`, `PIMPAPERID`, `CBSHKWMC`, `CREATEDATE`, `UPDATEDATE`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%i%s%i%s%s%s%s%s%s", iObj.getFbsj(), iObj.getCbs(), iObj.getKwqs(), iObj.getFj(),
												iObj.getGrzlwzzzdpm(), iObj.getKwmc(), iObj.getPimpapername(), idStr, iObj.getCbs(), datetime, datetime);
}

uint64_t t_pimpaperDAO::count(const PaperQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimpaper";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<t_pimpaperDO> t_pimpaperDAO::selectWithPage(const PaperQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT FBSJ, CBS, KWQS, FJ, GRZLWZZZDPM, KWMC, PIMPAPERNAME FROM t_pimpaper";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	t_pimpaperMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<t_pimpaperDO, t_pimpaperMapper>(sqlStr, mapper, params);
}

int t_pimpaperDAO::deleteById(string pimpaperid)
{
	string sql = "DELETE FROM `t_pimpaper` WHERE `PIMPAPERID`=?";
	return sqlSession->executeUpdate(sql, "%s", pimpaperid);
}
