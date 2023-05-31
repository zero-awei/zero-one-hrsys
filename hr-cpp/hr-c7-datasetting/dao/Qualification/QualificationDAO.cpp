#include "stdafx.h"
#include "QualificationDAO.h"
#include "QualificationMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define QUALIFICATION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->pimqualmajorid) { \
	sql << " AND `PIMQUALMAJORID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimqualmajorid.getValue("")); \
} \
if (query->qualevel) { \
	sql << " AND `QUALEVEL`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->qualevel.getValue("")); \
} \
if (query->pimqualmajorname) { \
	sql << " AND PIMQUALMAJORNAME=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->pimqualmajorname.getValue("")); \
} \
if (query->quamajor) { \
	sql << " AND QUAMAJOR=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->quamajor.getValue("")); \
}\

uint64_t QualificationDAO::count(const QualificationQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_pimqualmajor";
	QUALIFICATION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<QualificationDO> QualificationDAO::selectWithPage(const QualificationQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM t_pimqualmajor";
	QUALIFICATION_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	QualificationMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<QualificationDO, QualificationMapper>(sqlStr, mapper, params);
}

std::list<QualificationDO> QualificationDAO::selectByName(const string& name)
{
	string sql = "SELECT * FROM t_pimqualmajor WHERE `PIMQUALMAJORNAME` LIKE CONCAT('%',?,'%')";
	QualificationMapper mapper;
	return sqlSession->executeQuery<QualificationDO, QualificationMapper>(sql, mapper, "%s", name);
}

uint64_t QualificationDAO::insert(const QualificationDO& iObj)
{
	string sql = "INSERT INTO `t_pimqualmajor` (`PIMQUALMAJORID`, `QUALEVEL`, `PIMQUALMAJORNAME`, `QUAMAJOR`) VALUES (?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s", iObj.getpimQualMajorId(), iObj.getquaMajor(), iObj.getpimQualMajorName(), iObj.getquaMajor());
}

int QualificationDAO::update(const QualificationDO& uObj)
{
	string sql = "UPDATE `t_pimqualmajor` SET `QUALEVEL`=?, `PIMQUALMAJORNAME`=? ,`QUAMAJOR`=? WHERE `PIMQUALMAJORID`= ? ";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getquaMajor(), uObj.getpimQualMajorName(), uObj.getquaMajor(), uObj.getpimQualMajorId());
}

int QualificationDAO::deleteById(const std::string& id)
{
	stringstream sql;
	sql << "DELETE FROM t_pimqualmajor WHERE PIMQUALMAJORID=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, id);
	string sqlStr = sql.str();
	return sqlSession->executeUpdate(sqlStr, params);
}