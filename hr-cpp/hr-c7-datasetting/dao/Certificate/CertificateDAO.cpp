#include "stdafx.h"
#include "CertificateDAO.h"
#include "CertificateMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define CERTIFICATE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->seialno) { \
	sql << " AND `seialno`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->seialno.getValue(11)); \
} \
if (query->pimqualtypename) { \
	sql << " AND pimqualtypename=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimqualtypename.getValue("")); \
} \

uint64_t CertificateDAO::count(const CertificateQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM Certificate";
	CERTIFICATE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<CertificateDO> CertificateDAO::selectWithPage(const CertificateQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM Certificate";
	CERTIFICATE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CertificateMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CertificateDO, CertificateMapper>(sqlStr, mapper, params);
}

std::list<CertificateDO> CertificateDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM Certificate WHERE `pimqualtypename` LIKE CONCAT('%',?,'%')";
	CertificateMapper mapper;
	return sqlSession->executeQuery<CertificateDO, CertificateMapper>(sql, mapper, "%s", name);
}

uint64_t CertificateDAO::insert(const CertificateDO& iObj)
{
	string sql = "INSERT INTO `Certificate` (`seialno`, `pimqualtypename`) VALUES (?, ?)";
	return sqlSession->executeInsert(sql, "%i%s", iObj.getseialNo(), iObj.getpimQualTypeName());
}

int CertificateDAO::update(const CertificateDO& uObj)
{
	string sql = "UPDATE `Certificate` SET `pimqualtypename`=? WHERE `seialno`=?";
	return sqlSession->executeUpdate(sql, "%i%s", uObj.getseialNo(), uObj.getpimQualTypeName());
}

int CertificateDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `Certificate` WHERE `seialno`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
