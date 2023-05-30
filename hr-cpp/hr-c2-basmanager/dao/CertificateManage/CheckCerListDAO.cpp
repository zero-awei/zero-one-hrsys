/*
证书管理-分页查询证书列表--pine
*/
#include "stdafx.h"
#include "CheckCerListDAO.h"
#include "CheckCerListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define CERLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->ygbh) { \
    sql << " AND CAST(t1.ygbh AS CHAR) LIKE CONCAT('%', ?, '%')"; \
    SQLPARAMS_PUSH(params, "i", uint64_t, query->ygbh.getValue(0)); \
} \
if (query->pimperSonName) { \
    sql << " AND t2.pimperSonName?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->pimperSonName.getValue("")); \
} \
if (query->pimVocationalName) { \
    sql << " AND t1.pimVocationalName=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->pimVocationalName.getValue("")); \
}

uint64_t CheckCerListDAO::count(const CheckCerListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimvocational t1 LEFT JOIN t_pimperson t2 ON t1.ygbh = t2.ygbh";

	CERLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<CertificateDO> CheckCerListDAO::selectWithPage(const CheckCerListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t1.ygbh, t2.pimperSonName, t1.pimVocationalName FROM t_pimvocational t1 LEFT JOIN t_pimperson t2 ON t1.ygbh = t2.ygbh";

	CERLIST_TERAM_PARSE(query, sql);

	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;

	ChechCerListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CertificateDO, ChechCerListMapper>(sqlStr, mapper, params);
}

std::list<CertificateDO> CheckCerListDAO::selectByName(const string& pimVocationalName)
{
	string sql = "SELECT * FROM t_pimvocational WHERE `pimVocationalName` LIKE CONCAT('%',?,'%')";
	ChechCerListMapper mapper;
	return sqlSession->executeQuery<CertificateDO, ChechCerListMapper>(sql, mapper, "%s", pimVocationalName);
}
