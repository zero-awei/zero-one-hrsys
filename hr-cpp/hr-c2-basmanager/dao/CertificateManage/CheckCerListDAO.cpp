/*
证书管理-分页查询证书列表--pine
*/
#include "stdafx.h"
#include "CheckCerListDAO.h"
#include "CheckCerListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}

uint64_t CheckCerListDAO::count(const CheckCerListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<CertificateDO> CheckCerListDAO::selectWithPage(const CheckCerListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CertificateMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CertificateDO, CertificateMapper>(sqlStr, mapper, params);
}

std::list<CertificateDO> CheckCerListDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	CertificateMapper mapper;
	return sqlSession->executeQuery<CertificateDO, CertificateMapper>(sql, mapper, "%s", name);
}
